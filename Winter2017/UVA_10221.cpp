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

//-------------------END--------------------
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    double s, a;
    string ang;
    cout << fixed << setprecision(6);
    while(cin >> s >> a >> ang) {
        double pi = 2 * acos(0);
        s += 6440;
        double rad;
        if (ang == "deg") {
            rad = a * pi / 180;
        } else {
            rad = (a / 60) * pi / 180;
        }
        double interRad = rad;
        if (abs(interRad - 2 * pi) < EPS)
        {
            interRad = 0;
        }
        if(interRad > pi)
            interRad = abs(2 * pi - rad);
        //double check =
        cout << s * interRad << " " << sqrt(2 * s * s * (1 - cos(rad))) << "\n";
    }
    return 0;
}
