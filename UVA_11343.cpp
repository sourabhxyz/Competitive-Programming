#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000
const double PI = 2 * acos(0);

struct point {
    double x, y;
    point () {}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
    bool operator < (const point &other) const{
        if(abs(x - other.x) > eps) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point &other) const{
        return (abs(x - other.x) < eps && abs(y - other.y) < eps);
    }
};
double dist(point p1, point p2) { // Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); }
point rotate(point p, double theta) {
    double rad = theta * PI / 180;
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}
point rotatewrto(point p, point o, double theta) {
    double rad = theta * PI / 180;
    return point(o.x + (p.x - o.x) * cos(rad) - (p.y - o.y) * sin(rad),
                 o.y + (p.x - o.x) * sin(rad) + (p.y - o.y) * cos(rad));
}
struct vec { double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b)
{ // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) {
// nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s);
} // shorter.same.longer
point translate(point p, vec v) { // translate p according to v
    return point(p.x + v.x , p.y + v.y);
}
double dot(vec a, vec b)
{ return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v)
{ return v.x * v.x + v.y * v.y; }
double angle(point a, point o, point b)
{ // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < eps; }

struct line{
    double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
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

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > eps) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
// formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c);
} // Euclidean distance between p and c
// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y); // closer to a
        return dist(p, a); } // Euclidean distance between p and a
    if (u > 1.0) { c = point(b.x, b.y); // closer to b
        return dist(p, b); } // Euclidean distance between p and b
    return distToLine(p, a, b, c); } // run distToLine as above

struct linesegment{
    point a, b;
    line l;
    linesegment() {}
    linesegment(point aa, point bb, line ll) {
        a = aa; b = bb; l = ll;
    }
};


bool intersect(linesegment a, linesegment b) {
    line aa = a.l, bb = b.l;
    if(areSame(aa, bb)) {
        vector<point> temp;
        temp.push_back(a.a); temp.push_back(a.b);
        vector<point> temp2;
        temp2.push_back(b.a); temp2.push_back(b.b);
        sort(temp.begin(), temp.end());
        sort(temp2.begin(), temp2.end());
        //temp contains lineseg a, temp2 contains lineseg b
        point mx, mn;
        mx = max(temp[0], temp2[0]);
        mn = min(temp[1], temp2[1]);
        if(mx < mn || mx == mn) return true;
        else return false;
    }
    point inter;
    if(areIntersect(aa, bb, inter)) {
        if(inter.x > min(a.a.x, a.b.x) - eps and inter.x < max(a.a.x, a.b.x) + eps and inter.y > min(a.a.y, a.b.y) - eps and inter.y < max(a.a.y, a.b.y) + eps) {
            if(inter.x > min(b.a.x, b.b.x) - eps and inter.x < max(b.a.x, b.b.x) + eps and inter.y > min(b.a.y, b.b.y) - eps and inter.y < max(b.a.y, b.b.y) + eps) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<linesegment> data;
        for(int i = 0; i < n; i++) {
            point a, b;
            line l;
            cin >> a.x >> a.y >> b.x >> b.y;
            pointsToLine(a, b, l);
            data.push_back(linesegment(a, b, l));
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int tcnt = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(intersect(data[i], data[j])) continue;
                tcnt++;
            }
            if(tcnt == n - 1) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;

}
