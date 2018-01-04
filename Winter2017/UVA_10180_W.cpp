#include<bits/stdc++.h>

#define EPS 1e-9
#define INF 100000000

using namespace std;
struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS) // useful for sorting
            return x < other.x; // first criteria , by x-coordinate
        return y < other.y; }  // second criteria, by y-coordinate
// use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };
double dist(point p1, point p2) { // Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); } // return double
//------------------Line------------------------

struct line {
    double a, b, c;
    line() {}
    line(double a_, double b_, double c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }
    line(point p1, point p2)
    {
        if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
            a = 1.0; b = 0.0; c = -p1.x; // default values
        } else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0; // IMPORTANT: we fix the value of b to 1.0
            c = -(double)(a * p1.x) - p1.y;
        }
    }
    bool operator == (const line &other) const{
        return ((fabs(a - other.a) < EPS) && (fabs(b - other.b) < EPS) && (fabs(c - other.c) < EPS));
    }
};

struct vec { double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s); } // shorter.same.longer
point translate(point p, vec v) { // translate p according to v
    return point(p.x + v.x , p.y + v.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }
double distToLine(point p, point a, point b, point &c) {
// formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); } // Euclidean distance between p and c

double distToLineSegment(point v0, point v1, point c) { //returns the square of the req. dist.
    double vx = v0.x - c.x;
    double vy = v0.y - c.y;
    double ux = v1.x - v0.x;
    double uy = v1.y - v0.y;

    double length = ux * ux + uy * uy;

    double det = (-vx * ux) + (-vy * uy);

    if (det < EPS)
        return (v0.x - c.x) * (v0.x - c.x) + (v0.y - c.y) * (v0.y - c.y);
    if (det + EPS > length)
        return (v1.x - c.x) * (v1.x - c.x) + (v1.y - c.y) * (v1.y - c.y);

    det = ux * vy - uy * vx;
    return (det * det) / length;
}
//-------------------END--------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        point p1, p2;
        double r;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> r;
        vector<point> data;
        data.push_back(p1);
        data.push_back(p2);
        sort(data.begin(), data.end());
        point temp;
        double dist_ = sqrt(distToLineSegment(data[0], data[1], point(0, 0)));
        double ans = 0;
        if(dist_ > r - EPS)
        {
            ans = dist(data[0], data[1]);
            cout << fixed << setprecision(3) << ans << "\n";
            continue;
        }
        double d1 = sqrt(data[0].x * data[0].x + data[0].y * data[0].y);
        double t1 = sqrt(d1 * d1 - r * r);
        double d2 = sqrt(data[1].x * data[1].x + data[1].y * data[1].y);
        double t2 = sqrt(d2 * d2 - r * r);
        double d = dist(data[0], data[1]);
        double theta3 = acos((d1*d1 + d2*d2 - d*d) / (2*d1*d2));
        ans += t1;
        ans += t2;
        double theta1 = acos(0) - asin(r / d1);
        double theta2 = acos(0) - asin(r / d2);
        double arc = r * (theta3 - (theta1 + theta2));
        ans += arc;
        cout << fixed << setprecision(3) << ans << "\n";
    }
    return 0;
}
