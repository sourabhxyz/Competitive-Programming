// in 2d lib for polygon p[n - 1] = p[0] but this is not the case for 3d lib
#include <bits/stdc++.h>
using namespace std;
/* 2D Geo Lib */
#define inf 1000000000
const double eps = 1e-8;
const double pi = 2 * acos(0);
/* Point library starts */
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
ostream& operator<<(ostream& os, vec p) {
	if (abs(p.x) < eps) p.x = 0.000;
	if (abs(p.y) < eps) p.y = 0.000;
    return os << "("<< p.x << "," << p.y << ")";
}
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
// dot product doesn't change when one vector moves perpendicular to other.
double dot(vec a, vec b)
{ return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v)
{ return v.x * v.x + v.y * v.y; }
double angle(vec a, vec o, vec b)
{ // returns angle aob in rad
    vec oa = a - o, ob = b - o;
    /*Because of precision errors, we need to be careful not to call acos with a
value that is out of the allowable range [-1, 1].*/
    double costheta = dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob));
    return acos(max(-1.0, min(1.0, costheta)));
}
double angle(vec a, vec b) {
    double costheta = dot(a, b) / abs(a) / abs(b);
    return acos(max(-1.0, min(1.0, costheta)));
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(vec p, vec q, vec r) {
    return cross(q - p, r - q) > 0; }
/* bool ccw(vec p, vec q, vec r) { // I think this is better, but yeah we'll call ccw after checking for collinearity.
    return cross (q - p, r - q) > eps;
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
bool isPerp(vec p, vec q) {
    return (abs(dot(p, q)) < eps);
}
bool inAngle(vec a, vec b, vec c, vec x) {  // is point 'x' in angle between AB and AC?
    if (collinear(a, b, c)) {
        return collinear(a, c, x);
    }
    if (!ccw(a, b, c)) swap(b,c);
    // getting C on left of AB.
    return ccw(a,b,x) && !ccw(a,c,x);
}
double orientedAngle(vec a, vec b, vec c) {  // not getting angle between vectors but oriented angle.
    if (ccw(a, b, c))
        return angle(b-a, c-a);
    else  // i.e. B is on left of AC.
        return 2*pi - angle(b-a, c-a);
}
/* Point library ends */
/* ------------------------------------------------------------------
 * ------------Line library starts ---------------------------------
 */
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
void reduce(line &l) {
    if (abs(l.b) < eps) {
        double temp = l.a;
        l.a = 1;
        l.c /= temp;
    } else {
        double temp = l.b;
        l.b = 1;
        l.a /= temp;
        l.c /= temp;
    }
    return;
}
line vcToLine(vec v, double c) {  // basically v gives us a, b and acc. to him the eqn of line is ax + by = c. basically 'v' points in dirn perpendicular to line.
    line l;
    l.a = v.x, l.b = v.y;
    l.c = -c;
    reduce(l);
    return l;
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

/* The following code is incorrect */
double angle(line &l1, line &l2) { // returns the smaller angle b/w two lines <- not true...
    vec v1 = perp(vec(l1.a, l1.b));
    vec v2 = perp(vec(l2.a, l2.b));
    double ang = angle(v1, v2);
    if (ang > pi / 2) {
        return pi - ang;
    } else return ang;
}
/* Line perpendicular to l, and passing through p */
line perpthrough(vec p, line &l) {
    vec perpen(l.a, l.b);
    line ret;
    vecsToLine(p, p + perpen, ret);
    return ret;
}
/* For sorting along line */
/*vec b, a; // say that the line is defined to be a -> b
vec v = b - a;
auto cmpProj = [&](vec &a, vec &b) {
    return dot(v, a) < dot(v, b);
};*/
// translate the line by vector t. So if point p lies on line l then (p + t) lies on new line. i.e. c' = vec(l.a, l.b).(p + t) = -l.c + l.a * t.x + l.b * t.y.

line translate(line &l, vec t) {
    line ret = l;
    ret.c = l.c - l.a * t.x - l.b * t.y;
    return ret;
}
// shifting the line by amount d along its perpendicular
line translate(line &l, double d) {
    // shift the line up/down (depends on the sign of d) by d
    vec perpen(l.a, l.b);
    perpen = perpen / abs(perpen);
    perpen = perpen * d;
    return translate(l, perpen);
}
// dont know whether the following code works...
// we define internal bisector as the line whose direction vector points between the direction vector of l1 and l2.
vector<line> bisector(line &l1, line &l2) { // first one is internal, second one is external
    vec v1(l1.a, l1.b), v2(l2.a, l2.b);
    if (abs(cross(v1, v2)) < eps) {
        // not defined
    }
    double c1 = -l1.c, c2 = -l2.c;
    vector<line> ret;
    ret.push_back(vcToLine(v1 / abs(v1) + v2 / abs(v2), c1 / abs(v1) + c2 / abs(v2)));
    ret.push_back(vcToLine(v1 / abs(v1) - v2 / abs(v2), c1 / abs(v1) - c2 / abs(v2)));
    line l = ret[0];
    double ang = angle(l, l1);
    if (ang > pi / 4) {
        swap(ret[0], ret[1]);
    }
    return ret;
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
double distBwParallel(line &l1, line &l2) {
    // to compute distance between two parallel lines
    return (abs(l1.c - l2.c) / abs(vec(l1.a, l1.b)));
}
// distance between point p and line passing through ab.
double distToLine(vec p, vec a, vec b, vec &c) { // have to take care if a == b
// formula: c = a + u * ab
    vec ap = p - a, ab = b - a;
    if (a == b) {
        c = a;
        return dist(p, a);
    }
    double u = dot(ap, ab) / norm_sq(ab);
    c = a + (ab) * u;
    return dist(p, c);
} 
/* ------------------------------------------------------------------
 * ------------Line library ends ---------------------------------
 */
/* ------------------------------------------------------------------
 * ------------Linesegment library starts ---------------------------------
 */
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
bool lineseglinesegInterProper(linesegment &l1, linesegment &l2, vec &c) { // endpoint is in proper here
    if (areIntersect(l1.l, l2.l, c)) {
        if (lieson(l1, c) and lieson(l2, c)) {
            return true;
        } else return false;
    } else return false;
}
set<vec> lineseglinesegInter(linesegment &l1, linesegment &l2) {
    vec c;
    set<vec> ret;
    if (lineseglinesegInterProper(l1, l2, c)) {
        ret.insert(c);
        return ret;
    }
    if (liesonWithEq(l1, l2.a)) ret.insert(l2.a);
    if (liesonWithEq(l1, l2.b)) ret.insert(l2.b);
    if (liesonWithEq(l2, l1.a)) ret.insert(l1.a);
    if (liesonWithEq(l2, l1.b)) ret.insert(l1.b);
    return ret;
}
double distToLineSegment(vec p, vec a, vec b, vec &c) { // have to take care if a == b
    vec ap = p - a, ab = b - a;
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = vec(a.x, a.y); // closer to a
        return dist(p, a); } // Euclidean distance between p and a
    if (u > 1.0) { c = vec(b.x, b.y); // closer to b
        return dist(p, b); } // Euclidean distance between p and b
    return distToLine(p, a, b, c); } // run distToLine as above
double lineseglinesegDist(linesegment &l1, linesegment &l2) {
    vec temp;
    if (lineseglinesegInterProper(l1, l2, temp)) return 0;
    vec c;
    double ret = min(distToLineSegment(l2.a, l1.a, l1.b, c), min(distToLineSegment(l2.b, l1.a, l1.b, c), min(distToLineSegment(l1.a, l2.a, l2.b, c), distToLineSegment(l1.b, l2.a, l2.b, c))));
    return ret;
}
/* ------------------------------------------------------------------
 * ------------Line segment library ends ---------------------------------
 */
/* ------------------------------------------------------------------
 * ------------circle library starts ---------------------------------
 */
int circleLine(vec c, double r, line l, pair<vec, vec> &out) { // to tell circle line intersection, returns the number of intersection
    double h2 = (r * r) - sqdistToLine(c, l);
    if (h2 < -eps) return 0;  // no intersection
    if (abs(h2) < eps) {  // only one intersection
        vec p = proj(c, l);
        out = {p, p};
        return 1;
    }
    vec p = proj(c, l);
    vec h = unit(lineVec(l)) * sqrt(h2);
    out = {p - h, p + h};
    return 2;
}
// given two points on circle and circles radius, we can get two centers, to get the other center, call by swapping two points, I can easily derive a formula for this (by getting a line perpendicular to p1, p2 passing through their mid point and some specific distance away), so no need to bother about this code's logic.
bool circle2PtsRad(vec p1, vec p2, double r, vec &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; } // to get the other center, reverse p1 and p2

// // area of intersection of two circles
// double areaCircleCircleIntersection(vec o1, double r1, vec o2, double r2) {
//     vec d = o2 - o1; double d2 = norm_sq(d);
//     if (r1 < eps and r2 < eps) {
//         return 0;
//     }
//     if (d2 < eps) { // same or concentric circles
//         double temp = min(r1, r2);
//         return pi * temp * temp;
//     }
//     double ad = sqrt(d2);
//     if (ad < abs(r1 - r2) + eps) { // one is contained within other
//         double temp = min(r1, r2);
//         return pi * temp * temp;
//     }
//     if (ad > r1 + r2 - eps) {
//         return 0;
//     }
//     // phi is what intersection points have angle with o1, similarly for o2 we have theta.
//     double phi = acos(ad / (2 * r1)), theta = acos(ad / (2 * r2));
//     // 2l is the distance between intersecting points
//     double l = sqrt(r1 * r1 - (ad * ad) / 4);
//     // required area = sector 1 + sector 2 - area of rhombus
//     // area of rhombus = 1/2 * (2l) * (ad) = l * ad.
//     return (r1 * r1 * phi + r2 * r2 * theta - l * ad);
// }
// getting the point of intersection of two circles
void circleCircle(vec o1, double r1, vec o2, double r2) {
    vec d = o2 - o1; double d2 = norm_sq(d);
    if (r1 < eps and r2 < eps and d2 < eps) {
        cout << o1 << "\n";
        return;
    }
    if (d2 < eps and abs(r1 - r2) < eps) {
        cout << "THE CIRCLES ARE THE SAME\n";
        return;
    }
    if (d2 < eps) {
        cout << "NO INTERSECTION\n";
        return;
    }
    double ad = sqrt(d2);
    double pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
    double h2 = r1*r1 - pd*pd/d2; // = hˆ2
    vec p = o1 + d*pd/d2;
    if (abs(h2) < eps) { // only one intersection
        cout << p << "\n";
        return;
    } else if (h2 < -eps) {
        cout << "NO INTERSECTION\n";
        return;
    } else {
        vec h = perp(d)*sqrt(h2/d2);
        vector<vec> out = {p-h, p+h};
        sort(out.begin(), out.end());
        for (auto &pp : out) {
            cout << pp;
        }
        cout << "\n";
    }
}
// Getting area of intersection of two circles
double areacircleCircle(vec o1, double r1, vec o2, double r2) {
    vec d = o2 - o1; double d2 = norm_sq(d);
    if (r1 < eps and r2 < eps and d2 < eps) {
        cout << o1 << "\n";
        return;
    }
    if (d2 < eps and abs(r1 - r2) < eps) {
        cout << "THE CIRCLES ARE THE SAME\n";
        return;
    }
    if (d2 < eps) {
        cout << "NO INTERSECTION\n";
        return;
    }
    double ad = sqrt(d2);
    double pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
    double o1p = pd/ad;
    double o2p = ad - o1p;
    double h2 = r1*r1 - pd*pd/d2; // = hˆ2
    double ah = sqrt (h2);
    // phi is what intersection points have angle with o1, similarly for o2 we have theta.
    double phi = acos (o1p / r1);
    double theta = acos (o2p / r2);
    return (r1 * r1 * phi + r2 * r2 * theta - ah * ad);
}
/* ------------------------------------------------------------------
 * ------------circle library ends ---------------------------------
 */
/* ------------------------------------------------------------------
 * ------------polygon library starts ---------------------------------
 */
double tria(vec a, vec b, vec c) {
    double area = (a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x) / 2.0;
    return abs(area);
}
double perimeter(const vector<vec> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++) // remember that P[0] = P[n-1]
        result += dist(P[i], P[i+1]);
    return result; }

double areap(const vector<vec> &P) { // Either concave or convex, P[0] = P[n - 1]
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1); // observe that this is same as cross(p[i], p[(i + 1) % n])
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
    return P;
}

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
/* Polar sort function, useful to handle questions like: The are N points on the plane (N is even).
No three points belong to the same straight line. Your task is to select two points in such a way,
that straight line they belong to divides the set of points into two equal-sized parts.
Answer to this is simply, run polar sort, output data[0].second and data[n / 2].second */
/* Assumptions: No three points lie on a straight line */
/*typedef pair<vec, int> pvi;
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
}*/
/* ------------------------------------------------------------------
//-------------------------------------------------------------
/*CH1: For non collinear points*/
vec sa, sb;
vec pivot(0, 0);
bool angleCmp(vec a, vec b) { // angle-sorting function
   if (collinear(pivot, a, b)) // special case
       return dist(pivot, a) < dist(pivot, b); // check which one is closer
   double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
   double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
   return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; } // compare two angles
// atan2 returns principal arc tangent of y/x in the interval [-pi, pi].
// but since the pivot is bottommost and in case of tie, take the rightmost. That means all angles will lie in [0, pi]
vector<vec> CH1(vector<vec> P) { // the content of P may be reshuffled
   int i, j, n = (int)P.size();
   if (n <= 3) {
       if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
       return P; } // special case, the CH is P itself
// first, find P0 = point with lowest Y and if tie: rightmost X
   int P0 = 0;
   for (i = 1; i < n; i++)
       if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
           P0 = i;
   vec temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
// second, sort points by angle w.r.t. pivot P0
   pivot = P[0]; // use this global variable as reference
   sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
// third, the ccw tests
   vector<vec> S;
   S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
   i = 2; // then, we check the rest
   while (i < n) { // note: N must be >= 3 for this method to work
       j = (int)S.size()-1;
       if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
       else S.pop_back(); } // or pop the top of S until we have a left turn
   return S; } // return the result

/*CH2: Will accept collinear points but all points should be distinct*/
bool cmp(vec a, vec b) { // angle-sorting function
   if (collinear(pivot, a, b)) // special case
   {
       if (dot(sb - sa, a - sa) < eps) {  // dot product is <= 0 if angle b/w vectors >= 90.
           return dist(pivot, a) > dist(pivot, b);
       }
       else
           return dist(pivot, a) < dist(pivot, b); // check which one is closer
   }
   double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
   double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
   return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; } // compare two angles

vector<vec> CH2(vector<vec> P) { // the content of P may be reshuffled
   int i, j, n = (int)P.size();
   if (n <= 3) {
       P.push_back(P[0]); // safeguard from corner case
       return P; } // special case, the CH is P itself
// first, find P0 = point with lowest Y and if tie: rightmost X
   int P0 = 0;
   for (i = 1; i < n; i++)
       if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
           P0 = i;
   vec temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
// second, sort points by angle w.r.t. pivot P0
   pivot = P[0]; // use this global variable as reference
   sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
   sa = P[0], sb = P[1];
   sort(++P.begin(), P.end(), cmp);
// to be continued
   // continuation from the earlier part
// third, the ccw tests
   vector<vec> S;
   S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
   i = 2; // then, we check the rest
   while (i < n) { // note: N must be >= 3 for this method to work
       j = (int)S.size()-1;
       if (ccw(S[j-1], S[j], P[i]) || collinear(S[j - 1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
       else S.pop_back(); } // or pop the top of S until we have a left turn
   return S; } // return the result

//------------polygon library ends ---------------------------------
