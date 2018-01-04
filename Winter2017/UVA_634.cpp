/*I wasted quite a time trying to sort the input to process it the way I want, in the end realising that judge's input is always sorted*/
#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-7
double PI = 2 * acos(0);

struct point {
    int x, y;
    point() {}
    point(int xx, int yy) {
        x = xx; y = yy;
    }
};

double dist(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
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
// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0; // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]); // left turn/ccw
        else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw
    return fabs(fabs(sum) - 2*PI) < EPS; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    while(cin >> n && n) {
        vector<point> data;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            data.push_back(point(x, y));
        }
        data.push_back(data[0]);
        int x, y;
        cin >> x >> y;
        point tochk = point(x, y);
        if(inPolygon(tochk, data)) {
            cout << "T\n";
        }
        else cout << "F\n";
    }
    return 0;
}
