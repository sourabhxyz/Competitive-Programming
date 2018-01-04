#include<bits/stdc++.h>

using namespace std;

double PI = 2 * acos(0);
#define EPS 1e-7

struct point {
    double x, y;
    point () {}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
    bool operator < (const point &other) const{
        if(abs(y - other.y) > EPS) return y < other.y;
        return x < other.x;
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

double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }

bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0; // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]); // left turn/ccw
        else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw
    return fabs(fabs(sum) - 2*PI) < EPS; }

struct line{
    double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } }

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool ontri(point tochk, point a, point b, point c) {
    line ab, bc, ac;
    pointsToLine(a, b, ab); pointsToLine(b, c, bc); pointsToLine(a, c, ac);
    double x = tochk.x, y = tochk.y;
    if(x > min(a.x, b.x) - EPS && x < max(a.x, b.x) + EPS && y > min(a.y, b.y) - EPS && y < max(b.y, a.y) + EPS && abs(ab.a * tochk.x + ab.b * tochk.y + ab.c) < EPS) {
        return true;
    }

    if(x > min(b.x, c.x) - EPS && x < max(b.x, c.x) + EPS && y > min(c.y, b.y) - EPS && y < max(b.y, c.y) + EPS && abs(bc.a * tochk.x + bc.b * tochk.y + bc.c) < EPS) {
        return true;
    }
    if(x > min(a.x, c.x) - EPS && x < max(a.x, c.x) + EPS && y > min(c.y, a.y) - EPS && y < max(a.y, c.y) + EPS && abs(ac.a * tochk.x + ac.b * tochk.y + ac.c) < EPS) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << fixed << setprecision(2);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    point a, b, c;
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
        double xmin = 100, ymin = 100, xmax = 0, ymax = 0;
        if(a.x + b.x + c.x + a.y + b.y + c.y < EPS) break;
        xmin = min(xmin, min(a.x, min(b.x, c.x)));
        ymin = min(ymin, min(a.y, min(b.y, c.y)));
        xmax = max(xmax, max(a.x, max(b.x, c.x)));
        ymax = max(ymax, max(a.y, max(b.y, c.y)));
        xmin = ceil(xmin), xmax = floor(xmax), ymin = ceil(ymin), ymax = floor(ymax);
        int xxmin = max((int)xmin, 1), xxmax = min((int)xmax, 99), yymin = max((int)ymin, 1), yymax = min((int)ymax, 99);
        int cnt = 0;
        vector<point> poly;
        poly.push_back(a); poly.push_back(b); poly.push_back(c); poly.push_back(a);
        for(int i = xxmin; i <= xxmax; i++) {
            for(int j = yymin; j <= yymax; j++) {
                double area = tria(a, b, c);
                if(inPolygon(point(i, j), poly) || ontri(point(i, j), a, b, c)) //if(isinside(point(i, j), a, b, c, area))
                    cnt++;
            }
        }
        cout << setw(4) << cnt << "\n";
    }
    return 0;
}
