#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-9;
const double pi = acos(-1);
struct vec {
    double x, y;
    vec () {}
    vec(double xx, double yy) {
        x = xx; y = yy;
    }
    vec operator + (const vec &other) const {
        return vec(x + other.x, y + other.y);
    }
    vec operator - (const vec &other) const {
        return vec(x - other.x, y - other.y);
    }
    vec operator / (const double &div) const {
        return vec(x / div, y / div);
    }
    vec operator * (const double &mul) const {
        return vec(x * mul, y * mul);
    }
    bool operator < (const vec &other) const {
        if(abs(x - other.x) > eps) return x < other.x;
        return y < other.y;
    }
    bool operator == (const vec &other) const {
        return (abs(x - other.x) < eps && abs(y - other.y) < eps);
    }
};

vec perp(vec a) {
    return vec(-a.y, a.x);
}
double abs(vec a) {
    return sqrt(a.x * a.x + a.y * a.y);
}
double dist(vec a, vec b) {
    return hypot(a.x - b.x, a.y - b.y);
}
double sqVec(vec a) {
    return (a.x * a.x + a.y * a.y);
}
vec unit(vec a) {
    return (a / abs(a));
}
struct line{
    double a, b, c;
};

void vecsToLine(vec p1, vec p2, line &l) {
    if (fabs(p1.x - p2.x) < eps) { // vertical line is fine
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < eps) && (fabs(l1.b-l2.b) < eps); }
bool areSame(line l1, line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < eps); }

bool areIntersect(line l1, line l2, vec &p) {
    if (areParallel(l1, l2)) return false; // no intersection
    /* Above condition needs to modified if the same lines also need to be considered */
// solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > eps) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}
struct linesegment{
    vec a, b;
    line l;
    linesegment() {}
    linesegment(vec aa, vec bb) {
        vecsToLine(aa, bb, l);
        a = aa; b = bb;
    }
};
bool lieson(linesegment l, vec p) { // point 'p' needs to satisfy line equation seperately
    return (p.x > min(l.a.x, l.b.x) - eps and p.x < max(l.a.x, l.b.x) + eps and p.y > min(l.a.y, l.b.y) - eps and p.y < max(l.a.y, l.b.y) + eps);
}
bool liesonWithEq(linesegment &l, vec &p) {
    return (abs(l.l.a * p.x + l.l.b * p.y + l.l.c) < eps and lieson(l, p));
}
bool intersectLineSegWithLine(linesegment l1, line l2) { // Again linesegment could lie completely on line, handle it if required.
    vec p;
    return (areIntersect(l1.l, l2, p) and lieson(l1, p));
}
line abcToLine(double a, double b, double c) {
    if (abs(b) < eps) {
        double temp = a;
        a = 1;
        c /= temp;
    } else {
        double temp = b;
        b = 1;
        a /= temp;
        c /= temp;
    }
    line l;
    l.a = a; l.b = b; l.c = c;
    return l;
}

double dot(vec a, vec b)
{ return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v)
{ return v.x * v.x + v.y * v.y; }
double angle(vec a, vec o, vec b)
{ // returns angle aob in rad
    vec oa = a - o, ob = b - o;
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(vec p, vec q, vec r) {
    return cross(q - p, r - q) > 0; }
/* bool ccw(vec p, vec q, vec r) { // I think this is better
    double crs = cross(q - p, r - q);
    if (crs < eps) return 0;
    return 1;
} */
vec rotate(vec p, double theta) {
    double rad = theta * pi / 180;
    return vec(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad));
}
vec rotatewrto(vec p, vec o, double theta) {
    double rad = theta * pi / 180;
    return vec(o.x + (p.x - o.x) * cos(rad) - (p.y - o.y) * sin(rad),
               o.y + (p.x - o.x) * sin(rad) + (p.y - o.y) * cos(rad));
}

bool collinear(vec p, vec q, vec r) {
    return (abs(cross(q - p, r - q)) < eps);
}
double side(line &l, vec p) {
    return (l.a * p.x + l.b * p.y + l.c);
}
double sqdistToLine(vec p, line l) {
    return (side(l, p) * side(l, p) / (sqVec(vec(l.a, l.b))));
}
vec lineVec(line l) { // returns the vector parallel to line l
    return vec(l.b, -l.a);
}
vec proj(vec p, line l) { // projection of vec p on line l
    return (p - (perp(lineVec(l)) * side(l, p) / sqVec(lineVec(l))));
}
vec refl(vec p, line &l) { // returns reflection of the point p about line l
    return (p - (perp(lineVec(l)) * 2 * side(l, p) / sqVec(lineVec(l))));
}
double distToLine(vec p, line l, vec &c) {
    double d = abs(side(l, p)) / (sqrt(l.a * l.a + l.b * l.b));
    c = proj(p, l);
    return d;
}

double distToLine(vec p, vec a, vec b, vec &c) { // have to take care if a == b
// formula: c = a + u * ab
    vec ap = p - a, ab = b - a;
    double u = dot(ap, ab) / norm_sq(ab);
    c = a + (ab) * u;
    return dist(p, c);
} // Euclidean distance between p and c
// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(vec p, vec a, vec b, vec &c) { // have to take care if a == b
    vec ap = p - a, ab = b - a;
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = vec(a.x, a.y); // closer to a
        return dist(p, a); } // Euclidean distance between p and a
    if (u > 1.0) { c = vec(b.x, b.y); // closer to b
        return dist(p, b); } // Euclidean distance between p and b
    return distToLine(p, a, b, c); } // run distToLine as above

int circleLine(vec c, double r, line l, pair<vec, vec> &out) {
    double h2 = (r * r) - sqdistToLine(c, l);
    if (h2 < eps) return 0;
    vec p = proj(c, l);
    vec h = unit(lineVec(l)) * sqrt(h2);
    out = {p - h, p + h};
    return 1 + (h2 > eps);
}
double tria(vec a, vec b, vec c) {
    double area = (a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x) / 2.0;
    return abs(area);
}
double perimeter(const vector<vec> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++) // remember that P[0] = P[n-1]
        result += dist(P[i], P[i+1]);
    return result; }

double areap(const vector<vec> &P) { // Either concave or convex
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return abs(result) / 2.0; }
bool isConvex(const vector<vec> &P) { // returns true if all three
    int sz = (int)P.size(); // consecutive vertices of P form the same turns
    if (sz <= 3) return false; // a point/sz=2 or a line/sz=3 is not convex
    bool isLeft = ccw(P[0], P[1], P[2]); // remember one result
    for (int i = 1; i < sz-1; i++) // then compare with the others
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false; // different sign -> this polygon is concave
    return true; } // this polygon is convex
// line segment p-q intersect with line A-B.
vec lineIntersectSeg(vec p, vec q, vec A, vec B) { // same as intersection of a segment with line, p, q denotes endpoints of the segments and a, b deontes
    // point for line. Works only if we are sure that they intersect.
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return vec((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); }
// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<vec> cutPolygon(vec a, vec b, const vector<vec> &Q) { // Works only for convex polygon
    vector<vec> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(b - a, Q[i] - a), left2 = 0;
        if (i != (int)Q.size()-1) left2 = cross(b - a, Q[i + 1] - a);
        if (left1 > -eps) P.push_back(Q[i]); // Q[i] is on the left of ab
        if (left1 * left2 < -eps) // edge (Q[i], Q[i+1]) crosses line ab
            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front()); // make P’s first point = P’s last point
    return P; }
bool circle2PtsRad(vec p1, vec p2, double r, vec &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; } // to get the other center, reverse p1 and p2
bool insideoronpolygon(vector<vec> poly, vec tochk) { // Works only for convex polygon
    double polya = areap(poly);
    double areacmp = 0;
    for(int i = 0; i < poly.size() - 1; i++) {
        vec a = poly[i], b = poly[i + 1];
        areacmp += tria(a, b, tochk);
    }
    return abs(polya - areacmp) < eps;
}
bool inPolygon(vec pt, const vector<vec> &P) { // Works for both convex and concave. It implements
// winding number algorithm
    if ((int)P.size() == 0) return false;
    double sum = 0; // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]); // left turn/ccw
        else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw
    return fabs(fabs(sum) - 2*pi) < eps; }
bool inPolygonOrOn(vec pt, const vector<vec> &P) { // Works for both convex and concave
// polygon. Also accepts if the point lies on boundary
    if (inPolygon(pt, P)) return true;
    if ((int)P.size() == 0) return false;
    if (P.size() <= 3) return false;
    for (int i = 0; i < P.size() - 1; i++) {
        vec a = P[i], b = P[i + 1];
        linesegment l(a, b);
        if (liesonWithEq(l, pt)) return true;
    }
    return false;
}
/* Assumptions: No three points lie on a straight line */
typedef pair<vec, int> pvi;
vec pivot(0, 0);
bool angleCmp(pvi a, pvi b) { // angle-sorting function
    double d1x = a.first.x - pivot.x, d1y = a.first.y - pivot.y;
    double d2x = b.first.x - pivot.x, d2y = b.first.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; } // compare two angles
void polarSort(vector<pvi> &P) { // the content of P may be reshuffled
    int i, n = (int)P.size();
    if (n <= 2) { return; }
// first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].first.y < P[P0].first.y || (P[i].first.y == P[P0].first.y && P[i].first.x > P[P0].first.x))
            P0 = i;
    swap(P[P0], P[0]);
// second, sort points by angle w.r.t. pivot P0
    pivot = P[0].first; // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(3);
    int n;
    cin >> n;
    vector<pair<vec, int> > data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].first.x >> data[i].first.y;
        data[i].second = i + 1;
    }
    polarSort(data);
    cout << data[0].second << " " << data[n / 2].second << "\n";
}