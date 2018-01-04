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

bool ontri(point tochk, point a, point b, point c) {
    line ab, bc, ac;
    pointsToLine(a, b, ab); pointsToLine(b, c, bc); pointsToLine(a, c, ac);
    double x = tochk.x, y = tochk.y;
    if(x > a.x - EPS && x < b.x + EPS && y > a.y - EPS && y < b.y + EPS && abs(ab.a * tochk.x + ab.b * tochk.y + ab.c) < EPS) {
        return true;
    }

    if(x > b.x - EPS && x < c.x + EPS && y > b.y - EPS && y < c.y + EPS && abs(bc.a * tochk.x + bc.b * tochk.y + bc.c) < EPS) {
        return true;
    }
    if(x > a.x - EPS && x < c.x + EPS && y > a.y - EPS && y < c.y + EPS && abs(ac.a * tochk.x + ac.b * tochk.y + ac.c) < EPS) {
        return true;
    }
    return false;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout << fixed << setprecision(2);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    while(cin >> n && n) {
        vector<pair<point, int> > data;
        char ign;
        for(int i = 0; i < n; i++) {
            cin >> ign;
            double x, y;
            cin >> x >> y;
            data.push_back(make_pair(point(x, y), i));
        }
        sort(data.begin(), data.end());
        int one, two, three;
        double mx = -1;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    point a = data[i].first, b = data[j].first, c = data[k].first;
                    vector<point> poly;
                    poly.push_back(a); poly.push_back(b); poly.push_back(c); poly.push_back(a);
                    bool valid = true;
                    for(int l = 0; l < n; l++) {
                        if(l == i || l == j || l == k) continue;
                        if(inPolygon(data[l].first, poly)) {
                            valid = false;
                        }
                        if(ontri(data[l].first, a, b, c)) {
                            valid = false;
                        }
                    }
                    if(!valid) continue;
                    double arr = area(poly);
                    if(arr > mx) {
                        mx = arr;
                        one = data[i].second; two = data[j].second; three = data[k].second;
                    }
                }
            }
        }
        char first = 65 + one, second = 65 + two, third = 65 + three;
        vector<char> temp;
        temp.push_back(first); temp.push_back(second); temp.push_back(third);
        sort(temp.begin(), temp.end());
        cout << temp[0] << temp[1] << temp[2] << "\n";
    }
    return 0;
}
