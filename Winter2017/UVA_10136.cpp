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

double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0; }

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
bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; } // to get the other center, reverse p1 and p2

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool inside(point center, double radius, point tochk) {
    if(dist(center, tochk) < radius + EPS) {
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
    int t;
    cin >> t;
    cin.ignore();
    string line;
    getline(cin, line);
    double r = 2.5;
    while(t--) {
        int ans = 1;
        vector<point> data;
        double x, y;
        while(getline(cin, line) && line != "") {
            stringstream strm;
            strm << line;
            strm >> x >> y;
            data.push_back(point(x, y));
        }
        for(int i = 0; i < data.size(); i++) {
            for(int j = 0; j < data.size(); j++) {
                if(i == j) continue;
                point center;
                if(circle2PtsRad(data[i], data[j], 2.5, center)) {
                    int cnt = 0;
                    for(int k = 0; k < data.size(); k++) {
                        if(inside(center, r, data[k])) {
                            cnt++;
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << "\n";
        if(t) cout << "\n";
    }
    return 0;
}
