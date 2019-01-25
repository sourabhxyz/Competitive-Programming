#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-9;
const double pi = 2 * acos (0);
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
    T operator | (const v3 &other) {  // dot product
        return (x * other.x + y * other.y + z * other.z);
    }
    v3 operator * (const v3 &other) { // cross product
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
// consider the plane defined by pqr.
// basically n (normal) vector is along pq x pr
// returns (pq x pr) . (ps), +ve if s lies on same side of plane (i.e. n vec)
// 0 if s lies on the same plane (i.e. pqrs are coplanar) and -ve o/w
// orient remains the same under cyclic shift, and swapping any two elements changes its sign
// we can also say that orient is non zero iff lines pq and rs are skew (i.e. neither intersecting nor parallel), why? because intersecting and parallel lines lie on same plane, thus points p q r s lie on same plane. Ofcourse lines pq and rs are skew iff (pq x rs) . pr != 0 (another way)
// |orient (P, Q, R, S)| is equal to six times the volume of tetrahedron PQRS
T orient(v3 &p, v3 &q, v3 &r, v3 &s) {
    return (q - p) * (r - p) | (s - p);
}
// Lets say we have a plane P and a vec n (normal) perpendicular to it. If we replace PS by vec n we get 2D orient (p', q', r') on P, where p', q', r' are projections of p, q, r on P. 2D orient is just normal cross product of pq and pr. This 'n' should be a unit vector.
T orientByNormal(v3 p, v3 q, v3 r, v3 n) {return (q-p)*(r-p)|n;}
// eqn of plane is ax + by + cz = d where a, b, c determines the orientation of the plane and d determines its position relative to origin.
// eqn of plane is written as vec n . (x, y, z) = d.
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
// From two vectors u, v parallel to the plane we can find n.
// - these work with T = int
// side p is positive if p is on the side of plane P pointed by vec n. 0 if p lies on plane
// this is same as orient (p, q, r, s) where P is defined by plane p, q, r. 
    T side(v3 p) {
        return (n | p) - d;
    }
    double dist(v3 p) {
        return abs(side(p)) / abs(n);
    }
// translating a plane by vec t, suppose p lies on old plane, then p + t should lie on new plane, i.e. d' = n.(p + t) = n.p + n.t = d + n.t
    plane translate(v3 t) {
        return {n, d + (n | t)};
    }
// - these require T = double
// and if we want to shift perpendicularly (in direction of n) by some distance dist
    plane shiftUp(double dist) {
        // can easily be derived.
        return {n, d + dist * abs(n) };
    }
// projection of a point p on plane
// we know that p + kn is on plane, from that we get k = -side(p)/sq(n)
    v3 proj(v3 p) {
        return p - n * side(p) / sq(n);
    }
    v3 refl(v3 p) {
        return p - n * 2 * side(p) / sq(n);
    }
};
// coordinate system based on plane
// like suppose we have few point that we know are coplanar, and we want to use some 2d algorithm on them
// we define origin o on plane and two vectors dx, dy with norm 1 and perpendicular indicating direction of x, y axis.
// Now op.dx = x, op.dy = y, z = op.dz where dz = dx x dy.
struct coords {
    v3 o, dx, dy, dz;
// From three points P,Q,R on the plane:
    // build an orthonormal 3D basis
    coords() {}
    // getting coordinate system for plane defined by p, q, r.
    coords(v3 p, v3 q, v3 r) {
        o = p;
        dx = unit(q-p);
        dz = unit(dx*(r-p));
        dy = dz*dx;
        // we haven't made sure that norm is 1...
    }
// From four points P,Q,R,S:
// take directions PQ, PR, PS as is
// This can be useful if we don't care that the 2D coordinate system (dx, dy) is not orthonormal (perpendicular and of norm 1), because it allows us to keep using integer coordinate. If dx and dy are not perpendicular or do not have a norm of 1, the computed distances and angles will not be correct. But if we are only interested in the relative positions of lines and points, and finding the intersection of lines or segments, then everything works fine. Computing 2D convex hull is an example of such a problem, because it only requires that the sign of orient is correct.
    coords(v3 p, v3 q, v3 r, v3 s) :
            o(p), dx(q-p), dy(r-p), dz(s-p) {}
    vec pos2d(v3 p) {return {(p-o)|dx, (p-o)|dy};}
    v3 pos3d(v3 p) {return {(p-o)|dx, (p-o)|dy, (p-o)|dz};}
};
// line is defined as o + kd
struct line3d {
    v3 d, o;
    line3d() {}
// From two planes p1, p2 (requires T = double)
// getting line as a intersection of two planes
    line3d(plane p1, plane p2) {
        d = p1.n*p2.n;
// this o just works, can be seen by putting this o in both planes equation.
        o = (p2.n*p1.d - p1.n*p2.d)*d/sq(d);
    }
// From two points P, Q
    line3d(v3 p, v3 q) : d(q-p), o(p) {}
    // - these work with T = int
// distance of a point from line, is simply |unit(d) x op|
    double sqDist(v3 p) {
        return sq(d*(p-o))/sq(d);}
    double dist(v3 p) {return sqrt(sqDist(p));}
// sorting along a line
    bool cmpProj(v3 p, v3 q) {return (d|p) < (d|q);}
// - these require T = double
// projection of a point on line, o + (op.unit(d)) unit(d)
    v3 proj(v3 p) {return o + d*(d|(p-o))/sq(d);}
// refl(p) + p = 2proj(p)
    v3 refl(v3 p) {return proj(p)*2 - p;}
// plane line intersection
// n.(o + kd) = planes d => k = (d - n.o) / n.d = -side (o) / n.d
    v3 inter(plane p) {return o - d*p.side(o)/(d|p.n);} // Note, it could
    // be that vec(n).vec(d) is 0 i.e. line is parallel to the plane
    // in that case either there is no intersection or infinitely many
    // intersection...
};
double dist(line3d l1, line3d l2) {
    v3 n = l1.d*l2.d;
    if (n == zero) // parallel
        return l1.dist(l2.o);
// i.e. lines are either intersecting or are skew.
// Define n = d1 x d2, i.e. n is direction which is perpendicular to both lines
// Distance C1C2 = |C1C2.n|/|n| = |C1C2| (just mentioning). Now dot product doesn't change when one of the vectors move perpendicular to other => dis = |O1C2.n|/|n| = |O1O2.n|/|n|.
    return abs((l2.o-l1.o)|n)/abs(n);
}
// Now to find C1, C2, consider plane P which contains l2 and has normal = d2 x n, thus this planes intersection with l1 gives us C1. which we can find as before
v3 closestOnL1(line3d l1, line3d l2) {
    v3 n2 = l2.d*(l1.d*l2.d);
    return l1.o + l1.d*((l2.o-l1.o)|n2)/(l1.d|n2);
}
// angle between two planes is same as angle between normals. Usually we'll get two angles theta and pi - theta, we'll take smaller of two.
double smallAngle(v3 v, v3 w) {
    return acos(min(abs(v|w)/abs(v)/abs(w), 1.0));
}
double angle(plane p1, plane p2) {
    return smallAngle(p1.n, p2.n);
}
bool isParallel(plane p1, plane p2) {
    return p1.n*p2.n == zero;  // need to be modified a bit
}
bool isPerpendicular(plane p1, plane p2) {
    return abs(p1.n|p2.n) < eps;
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
// angle between a plane and a line is pi/2 - angle between line and normal
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
// v3 o need not lie on plane.
line3d perpThrough(plane p, v3 o) {return line3d(o, o+p.n);}
plane perpThrough(line3d l, v3 o) {return plane(l.d, o);}
// A polyhedron is a region of space delimited by polygonal faces
// Some properties of polyhedron
// # all faces are polygons that don't intersect
// # two faces either share a complete edge or share a single vertex or have no common point
// # all edges are shared by exactly two faces
// # if we define adjacent faces that share an edge, all faces are connected together.
// Two compute surface area of a polyhedron we need to add the area of its faces.
v3 vectorArea2(vector<v3> p) { // vector area * 2 (to avoid divisions)
    v3 S = zero;
    for (int i = 0, n = p.size(); i < n; i++)
        S = S + p[i]*p[(i+1)%n]; // all distinct points, i.e.
        // last point is not same as first point
    return S;
}
// computes area of a particular face. Look at photo.
double area(vector<v3> p) {
    return abs(vectorArea2(p)) / 2.0;
}
struct edge {
    int v;
    bool same; // = is the common edge in the same order?
};
// Given a series of faces (lists of points), reverse some of them
// so that their orientations are consistent
// Basically we want all vector areas S to either point inside the polyhedron or outside. So the following function achieves that.
//  Note that because of circularity in P1, P2, ... , Pn, Pn is considered to come before P1 and not after.
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
    flip[0] = false;  // i.e. no need to reverse the edges of first face.
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
// Once we have correct (either all outside or all inside) orientation, we can compute the area of polyhedron
// Area of pyramid OP1P2...Pn is equal to area of base * height/3. So area of base * height = S . op1.
double volume(vector<vector<v3>> fs) {
    double vol6 = 0.0;
    for (vector<v3> f : fs)
        vol6 += (vectorArea2(f)|f[0]);
    // divide by 6 because in the end we were required to divide by 2 aswell because we are calculating vectorArea2.
    return abs(vol6) / 6.0;
}
// Spherical geometry
// lat [-pi/2, pi/2] tells us how for north the point is. and lon (-pi, pi] tells us how far east the point is.
// the following function returns the coordinates of a point on sphere.
v3 sph(double r, double lat, double lon) {
    lat *= pi/180, lon *= pi/180;
    return {r*cos(lat)*cos(lon), r*cos(lat)*sin(lon), r*sin(lat)};
}
// sphere line intersection, same as circle line intersection
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
// the shortest distance between two points a and b on a sphere (o, r). 
// this code also works if a and b are not actually on the sphere, in which case it will give the distance between their projections on sphere.
double greatCircleDist(v3 o, double r, v3 a, v3 b) {
    return r * angle(a-o, b-o);
}
// returns 1 if x is greater than 0. 
// returns 0 if x is 0
// returns -1 if x is < 0. 
int sgn(double x) {
    if (abs(x) < eps) {
        return 0;
    }
    return (eps < x) - (x < -eps);
}
// In the following discussion, center of sphere is assumed to be origin.
/* For points a and b on a spere, we define sperical segment [a, b] as the path drawn by the great circle distance between a and b on the sphere. This is not well defined if a and b are directly opposite to each other on the sphere because there would be many possible shortest paths
*/
// we call a segment [a, b] valid if a and b are not opposite to each other. 
// Note that this function accepts segments where p = q.
bool validSegment(v3 p, v3 q) {
    return p*q != zero || (p|q) > eps;
}
// segment segment intersection.
// Note that the intersection point I must be in the intersection of planes OAB and OCD. So direction OI must be perpendicular to their normals A x B and C x D, that is parallel to (A x B) x (C x D). Multiplying this by the sign of od gives the correct direction. Note that out only gives the direction of the intersection. If we want to find the intersection on the sphere we need to scale it to have length r.
bool properInter(v3 a, v3 b, v3 c, v3 d, v3 &out) {
    v3 ab = a*b, cd = c*d; // normals of planes OAB and OCD
    int oa = sgn(cd|a),
            ob = sgn(cd|b),
            oc = sgn(ab|c),
            od = sgn(ab|d);
    out = ab*cd*od; // four multiplications => careful with overflow!
    return (oa != ob && oc != od && oa != oc);
}
// To check whether the point p is in segment [a, b]
bool onSphSegment(v3 a, v3 b, v3 p) {
    v3 n = a*b;
    // special case when a == b, in which we just check whether p == a.
    if (n == zero)
        return a*p == zero && (a|p) > eps;
    return (n|p) == 0 && (n|a*p) > -eps && (n|b*p) < eps;
}

struct directionSet : vector<v3> {
    using vector::vector; // import constructors
    void insert(v3 p) {
        for (v3 q : *this) if (p*q == zero) return;  // not considering duplicates
        push_back(p);
    }
};
// putting it all together
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
// to compute angle between spherical segment ab and ac.
// this is same as angle between planes oab and oac.
double angleSph(v3 a, v3 b, v3 c) {
    return angle(a*b, a*c);
}
// see photo
double orientedAngleSph(v3 a, v3 b, v3 c) {
    if ((a*b|c) >= 0)
        return angleSph(a, b, c);
    else
        return 2 * pi - angleSph(a, b, c);
}
// as always, all points in p are distinct i.e. p[0] != p[n - 1]
// just know that this can be derived.
double areaOnSphere(double r, vector<v3> p) {
    int n = p.size();
    double sum = -(n-2)* pi;
    for (int i = 0; i < n; i++)
        sum += orientedAngleSph(p[(i+1)%n], p[(i+2)%n], p[i]);
    return r*r*sum;
}
/*is the volume of the parallelepiped with base vectors (u and v) and vertical vector as w.*/
int main () {
    return 0;
}