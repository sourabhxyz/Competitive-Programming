#include<bits/stdc++.h>

using namespace std;

double PI = 2 * acos(0);
#define EPS 1e-7
#define INF 100000000
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
    bool operator == (const point &other) const{
        return (abs(x - other.x) < EPS && abs(y - other.y) < EPS);
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

bool areParallel(line l1, line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }
bool areSame(line l1, line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true; }

double tria(point a, point b, point c) {
    double area = (a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x) / 2.0;
    return abs(area);
}

double areap(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int roads;
    cin >> roads;
    for(int tc = 1; tc <= roads; tc++) {
        cout << "Road #" << tc << ":\n";
        int rp, trees;
        cin >> rp >> trees;
        vector<point> rpd;
        for(int i = 0; i < rp; i++) {
            double x, y;
            cin >> x >> y;
            rpd.push_back(point(x, y));
        }
        double totallength = 0;
        for(int i = 0; i < rp - 1; i++) {
            double dis = dist(rpd[i], rpd[i + 1]);
            totallength += dis;
        }
        double gapdistance = totallength / (trees - 1);
        //vec fr = toVec(rpd[0], rpd[1]);
        //fr = scale(fr, 1.0 / dist(rpd[0], rpd[1]));
        int onseg = 0;
        point currtree = rpd[0];
        vector<point> treedata;
        treedata.push_back(currtree);
        for(int i = 1; i <= trees - 2; i++) {
            point prevtree = currtree;
            double tocover = gapdistance;
            bool done = false;
            while(!done) {
                if(dist(prevtree, rpd[onseg + 1]) > tocover - EPS) {
                    if(abs(dist(prevtree, rpd[onseg + 1]) - tocover) < EPS) { //this if is not needed, but it may solve my problem
                        currtree = rpd[onseg + 1];
                        done = true;
                    }
                    else {
                        vec fr = toVec(rpd[onseg], rpd[onseg + 1]);
                        fr = scale(fr, 1.0 / dist(rpd[onseg], rpd[onseg + 1]));
                        currtree = translate(prevtree, scale(fr, tocover));
                        done = true;
                    }
                }
                else {
                    tocover = tocover - dist(prevtree, rpd[onseg + 1]);
                    prevtree = rpd[onseg + 1];
                    onseg++;
                }
            }
            treedata.push_back(currtree);
        }
        treedata.push_back(rpd[rpd.size() - 1]);
        for(int i = 0; i < treedata.size(); i++) {
            cout << treedata[i].x << " " << treedata[i].y << "\n";
        }
        cout << "\n";
    }
    return 0;
}
