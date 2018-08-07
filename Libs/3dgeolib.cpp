/* 3D geometry lib */
typedef double T;
struct v3 {
    T x, y, z;
    v3() {}
    v3(T xx, T yy, T zz) {
        x = xx; y = yy; z = zz;
    }
    v3 operator + (const v3 &other) {
        return v3(x + other.x, y + other.y, z + other.z);
    }
    v3 operator - (const v3 &other) {
        return v3(x - other.x, y - other.y, z - other.z);
    }
    v3 operator * (const double &dd) {
        return v3(x * dd, y * dd, z * dd);
    }
    v3 operator / (const double &dd) {
        return v3(x / dd, y / dd, z / dd);
    }
    T operator | (const v3 &other) {
        return (x * other.x + y * other.y + z * other.z);
    }
    v3 operator * (const v3 &other) {
        return (v3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x));
    }
    bool operator == (const v3 &other) {
        return (abs(x - other.x) < eps and abs(y - other.y) < eps and abs(z - other.z) < eps);
    }
    bool operator != (const v3 &other) {
        return (!(*this == other));
    }
    bool operator < (const v3 &other) const {
        return tie(x, y, z) < tie(other.x, other.y, other.y);
    }
};
const v3 zero(0, 0, 0);
T sq(v3 p) {
    return p | p;
}
T abs(v3 p) {
    return sqrt(sq(p));
}
v3 unit(v3 p) {
    return p / (abs(p));
}
T angle(v3 v1, v3 v2) {
    double costheta = (v1 | v2) / abs(v1) / abs(v2);
    return acos(max(-1.0, min(1.0, costheta)));
}
// returns (pq x pr) . (ps), +ve if s lies on same side of plane (i.e. n vec)
// 0 if s lies on the same plane and -ve o/w
T orient(v3 &p, v3 &q, v3 &r, v3 &s) {
    return (q - p) * (r - p) | (s - p);
}
T orientByNormal(v3 p, v3 q, v3 r, v3 n) {return (q-p)*(r-p)|n;}
struct plane { // different plane equations can essentially be same, (i.e. differ only by a const.
    // factor). To avoid that you can normalise vector n, i.e. divide vec(n) by |vec(n)|.
    // Also note that d / |vec(n)| represents distance of the plane from origin.
    v3 n; T d;
// From normal n and offset d
    plane(v3 n, T d) : n(n), d(d) {}
// From normal n and point P
    plane(v3 n, v3 p) : n(n), d(n|p) {}
// From three non-collinear points P,Q,R
    plane(v3 p, v3 q, v3 r) : plane((q-p)*(r-p), p) {}
// Will be defined later:
// - these work with T = int
    T side(v3 p) {
        return (n | p) - d;
    }
    double dist(v3 p) {
        return abs(side(p)) / abs(n);
    }
    plane translate(v3 t) {
        return {n, d + (n | t)};
    }
// - these require T = double
    plane shiftUp(double dist) {
        // can easily be derived.
        return {n, d + dist * abs(n) };
    }
    v3 proj(v3 p) {
        return p - n * side(p) / sq(n);
    }
    v3 refl(v3 p) {
        return p - n * 2 * side(p) / sq(n);
    }
};
struct coords {
    v3 o, dx, dy, dz;
// From three points P,Q,R on the plane:
    // build an orthonormal 3D basis
    coords() {}
    coords(v3 p, v3 q, v3 r) {
        o = p;
        dx = unit(q-p);
        dz = unit(dx*(r-p));
        dy = dz*dx;
    }
// From four points P,Q,R,S:
// take directions PQ, PR, PS as is
    coords(v3 p, v3 q, v3 r, v3 s) :
            o(p), dx(q-p), dy(r-p), dz(s-p) {}
    vec pos2d(v3 p) {return {(p-o)|dx, (p-o)|dy};}
    v3 pos3d(v3 p) {return {(p-o)|dx, (p-o)|dy, (p-o)|dz};}
};
struct line3d {
    v3 d, o;
    line3d() {}
    line3d(plane p1, plane p2) {
        d = p1.n*p2.n;
        o = (p2.n*p1.d - p1.n*p2.d)*d/sq(d);
    }
// From two points P, Q
    line3d(v3 p, v3 q) : d(q-p), o(p) {}
// From two planes p1, p2 (requires T = double)
// Will be defined later:
    // - these work with T = int
    double sqDist(v3 p) {
        return sq(d*(p-o))/sq(d);}
    double dist(v3 p) {return sqrt(sqDist(p));}
    bool cmpProj(v3 p, v3 q) {return (d|p) < (d|q);}
// - these require T = double
    v3 proj(v3 p) {return o + d*(d|(p-o))/sq(d);}
    v3 refl(v3 p) {return proj(p)*2 - p;}
    v3 inter(plane p) {return o - d*p.side(o)/(d|p.n);} // Note, it could
    // be that vec(n).vec(d) is 0 i.e. line is parallel to the plane
    // in that case either there is no intersection or infinitely many
    // intersection...
};
double dist(line3d l1, line3d l2) {
    v3 n = l1.d*l2.d;
    if (n == zero) // parallel
        return l1.dist(l2.o);
    return abs((l2.o-l1.o)|n)/abs(n);
}
v3 closestOnL1(line3d l1, line3d l2) {
    v3 n2 = l2.d*(l1.d*l2.d);
    return l1.o + l1.d*((l2.o-l1.o)|n2)/(l1.d|n2);
}
// Note in case angle b/w v, w is greater than 90 deg, then what we
// want is actually v . (-w), which would be same as taking absolute
double smallAngle(v3 v, v3 w) {
    return acos(min(abs(v|w)/abs(v)/abs(w), 1.0));
}
double angle(plane p1, plane p2) {
    return smallAngle(p1.n, p2.n);
}
bool isParallel(plane p1, plane p2) {
    return p1.n*p2.n == zero;
}
bool isPerpendicular(plane p1, plane p2) {
    return (p1.n|p2.n) == 0;
}
double angle(line3d l1, line3d l2) {
    return smallAngle(l1.d, l2.d);
}
bool isParallel(line3d l1, line3d l2) {
    return l1.d*l2.d == zero;
}
bool isPerpendicular(line3d l1, line3d l2) {
    return abs(l1.d|l2.d) < eps;
}
double angle(plane p, line3d l) {
    return pi/2 - smallAngle(p.n, l.d);
    // we take small angle because angle b/w plane and line
    // can atmost be 90 deg
}
bool isParallel(plane p, line3d l) {
    return abs(p.n|l.d) < eps;
}
bool isPerpendicular(plane p, line3d l) {
    return p.n*l.d == zero;
}
line3d perpThrough(plane p, v3 o) {return line3d(o, o+p.n);}
plane perpThrough(line3d l, v3 o) {return plane(l.d, o);}
v3 vectorArea2(vector<v3> p) { // vector area * 2 (to avoid divisions)
    v3 S = zero;
    for (int i = 0, n = p.size(); i < n; i++)
        S = S + p[i]*p[(i+1)%n]; // all distinct points, i.e.
        // last point is not same as first point
    return S;
}
double area(vector<v3> p) {
    return abs(vectorArea2(p)) / 2.0;
}
struct edge {
    int v;
    bool same; // = is the common edge in the same order?
};
// Given a series of faces (lists of points), reverse some of them
// so that their orientations are consistent
void reorient(vector<vector<v3>> &fs) {
    int n = fs.size();
// Find the common edges and create the resulting graph
    vector<vector<edge>> g(n);
    map<pair<v3,v3>,int> es;
    for (int u = 0; u < n; u++) { // going through all faces
        for (int i = 0, m = fs[u].size(); i < m; i++) { // going through
            // all its edges
            v3 a = fs[u][i], b = fs[u][(i+1)%m]; // clearly last point
            // is not the same as first point
// Let’s look at edge [AB]
            if (es.count({a,b})) { // seen in same order
                // we have to flip when the order is same
                int v = es[{a,b}];
                g[u].push_back({v,true});
                g[v].push_back({u,true});
            } else if (es.count({b,a})) { // seen in different order
                int v = es[{b,a}];
                g[u].push_back({v,false});
                g[v].push_back({u,false});
            } else { // not seen yet
                es[{a,b}] = u;
            }
        }
    }
// Perform BFS to find which faces should be flipped
    vector<bool> vis(n,false), flip(n);
    flip[0] = false; // if I
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (edge e : g[u]) {
            if (!vis[e.v]) {
                vis[e.v] = true;
// If the edge was in the same order,
// exactly one of the two should be flipped
                flip[e.v] = (flip[u] ^ e.same);
                q.push(e.v);
            }
        }
    }
    // Actually perform the flips
    for (int u = 0; u < n; u++)
        if (flip[u])
            reverse(fs[u].begin(), fs[u].end());
}
double volume(vector<vector<v3>> fs) {
    double vol6 = 0.0;
    for (vector<v3> f : fs)
        vol6 += (vectorArea2(f)|f[0]);
    return abs(vol6) / 6.0;
}
v3 sph(double r, double lat, double lon) {
    lat *= pi/180, lon *= pi/180;
    return {r*cos(lat)*cos(lon), r*cos(lat)*sin(lon), r*sin(lat)};
}
int sphereLine(v3 o, double r, line3d l, pair<v3,v3> &out) {
    double h2 = r*r - l.sqDist(o);
    if (h2 < -eps) return 0; // the line doesn’t touch the sphere
    v3 p = l.proj(o); // point P
    if (abs(h2) < eps) {
        out = {p, p};
        return 1;
    }
    v3 h = l.d*sqrt(h2)/abs(l.d); // vector parallel to l, of length h
    out = {p-h, p+h};
    return 2;
}
double greatCircleDist(v3 o, double r, v3 a, v3 b) {
    return r * angle(a-o, b-o);
}
int sgn(double x) {
    if (abs(x) < eps) {
        return 0;
    }
    return (eps < x) - (x < -eps);
}
// norm is equal to mod (vector) square
bool validSegment(v3 p, v3 q) {
    return p*q != zero || (p|q) > eps;
}
bool properInter(v3 a, v3 b, v3 c, v3 d, v3 &out) {
    v3 ab = a*b, cd = c*d; // normals of planes OAB and OCD
    int oa = sgn(cd|a),
            ob = sgn(cd|b),
            oc = sgn(ab|c),
            od = sgn(ab|d);
    out = ab*cd*od; // four multiplications => careful with overflow!
    return (oa != ob && oc != od && oa != oc);
}
bool onSphSegment(v3 a, v3 b, v3 p) {
    v3 n = a*b;
    if (n == zero)
        return a*p == zero && (a|p) > eps;
    return (n|p) == 0 && (n|a*p) > -eps && (n|b*p) < eps;
}
struct directionSet : vector<v3> {
    using vector::vector; // import constructors
    void insert(v3 p) {
        for (v3 q : *this) if (p*q == zero) return;
        push_back(p);
    }
};
directionSet intersSph(v3 a, v3 b, v3 c, v3 d) {
    assert(validSegment(a, b) && validSegment(c, d));
    v3 out;
    if (properInter(a, b, c, d, out)) return {out};
    directionSet s;
    if (onSphSegment(c, d, a)) s.insert(a);
    if (onSphSegment(c, d, b)) s.insert(b);
    if (onSphSegment(a, b, c)) s.insert(c);
    if (onSphSegment(a, b, d)) s.insert(d);
    return s;
}
double angleSph(v3 a, v3 b, v3 c) {
    return angle(a*b, a*c);
}
double orientedAngleSph(v3 a, v3 b, v3 c) {
    if ((a*b|c) >= 0)
        return angleSph(a, b, c);
    else
        return 2 * pi - angleSph(a, b, c);
}
// as always, all points in p are distinct i.e. p[0] != p[n - 1]
double areaOnSphere(double r, vector<v3> p) {
    int n = p.size();
    double sum = -(n-2)* pi;
    for (int i = 0; i < n; i++)
        sum += orientedAngleSph(p[(i+1)%n], p[(i+2)%n], p[i]);
    return r*r*sum;
}
/*is the volume of the parallelepiped with base vectors (u and v) and vertical vector as w.*/