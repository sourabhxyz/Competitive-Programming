/*The toughest problem I have ever done*/

#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-7
double PI = 2 * acos(0);

struct point {
    int x, y;
    point () {}
    point(int xx, int yy) {
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
double perimeter(const vector<point> &P) {
    double result = 0.0;
    /*if(P.size() == 3) {
        return dist(P[0], P[1]);
    }*/
    for (int i = 0; i < (int)P.size()-1; i++) // remember that P[0] = P[n-1]
        result += dist(P[i], P[i+1]);
    return result; }

double areap(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return abs(result) / 2.0; }

point sa, sb;
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }
point pivot(0, 0);
bool angleCmp(point a, point b) { // angle-sorting function
    if (collinear(pivot, a, b)) // special case
        return dist(pivot, a) < dist(pivot, b); // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; } // compare two angles
bool cmp(point a, point b) { // angle-sorting function
    if (collinear(pivot, a, b)) // special case
    {
        if (dot(toVec(sa, sb), toVec(sa, a)) < EPS) {
            return dist(pivot, a) > dist(pivot, b);
        }
        else
           return dist(pivot, a) < dist(pivot, b); // check which one is closer
    }
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; } // compare two angles

vector<point> CH(vector<point> P) { // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P; } // special case, the CH is P itself
// first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
// second, sort points by angle w.r.t. pivot P0
    pivot = P[0]; // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
    sa = P[0], sb = P[1];
    sort(++P.begin(), P.end(), cmp);
// to be continued
    // continuation from the earlier part
// third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
    i = 2; // then, we check the rest
    while (i < n) { // note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i]) || collinear(S[j - 1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
        else S.pop_back(); } // or pop the top of S until we have a left turn
    return S; } // return the result

struct tree{
    point loc;
    int val, id;
    double lensup;
    tree() {}
    tree(point ll, int vv, double le, int ii) {
        loc = ll; val = vv; lensup = le; id = ii;
    }
};

bool isinside(point tochk, point a, point b, point c, double area) {
    double area_ = tria(a, b, tochk);
    area_ += tria(a, tochk, c);
    area_ += tria(tochk, b, c);
    return (area_ <= area + EPS)? true : false;
}
map<point, int> cnt, cnt2;

bool insidepolygon(vector<point> poly, point tochk, int which) {
    if(poly.empty()) return false;
    if(poly.size() <= 3) {
        if(which == 0)
            if((poly[0] == tochk && cnt[poly[0]] >= 3) || poly[1] == tochk && cnt[poly[1]] >= 3) return true;
        if(which == 1)
            if((poly[0] == tochk && cnt2[poly[0]] >= 3) || poly[1] == tochk && cnt2[poly[1]] >= 3) return true;
        //if(poly[0] == tochk) return true;

        return false;
    }
    double polya = areap(poly);
    if(abs(polya) < EPS) { //that means we have a line;
        point a = poly[0], b = poly[poly.size() - 2];
        line ab;
        pointsToLine(a, b, ab);
        if(tochk.x >= min(a.x, b.x) && tochk.x <= max(a.x, b.x) && tochk.y >= min(a.y, b.y) && tochk.y <= max(a.y, b.y)) {
            if(abs(ab.a * tochk.x + ab.b * tochk.y + ab.c) < EPS) return true;
            return false;
        }
        else return false;
    }
    double areacmp = 0;
    for(int i = 0; i < poly.size() - 1; i++) {
        point a = poly[i], b = poly[i + 1];
        areacmp += tria(a, b, tochk);
    }
    return abs(polya - areacmp) < EPS;
    
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(4);
    int c, r, o, t = 1;
    while(cin >> c >> r >> o && (c + r + o) != 0) {
        vector<point> cops, robbers, citizens;
        for(int i = 0; i < c; i++) {
            int x, y;
            cin >> x >> y;
            cnt[point(x, y)]++;
            cops.push_back(point(x, y));
        }
        sort(cops.begin(), cops.end());
        vector<point>::iterator it;
        it = unique(cops.begin(), cops.end());
        cops.resize(distance(cops.begin(), it));
        for(int i = 0; i < r; i++) {
            int x, y;
            cin >> x >> y;
            cnt2[point(x, y)]++;
            robbers.push_back(point(x, y));
        }
        sort(robbers.begin(), robbers.end());
        it = unique(robbers.begin(), robbers.end());
        robbers.resize(distance(robbers.begin(), it));
        for(int i = 0; i < o; i++) {
            int x, y;
            cin >> x >> y;
            citizens.push_back(point(x, y));
        }
        vector<point> copsch, robberch;
        if(cops.empty()) {
            copsch = cops;
        }
        else {
            copsch = CH(cops);
        }
        if(robbers.empty()) {
            robberch = robbers;
        }
        else {
            robberch = CH(robbers);
        }
        vector<int> cstatus;
        cstatus.assign(o, -1);
        for(int i = 0; i < o; i++) {
            if(insidepolygon(copsch, citizens[i], 0)) {
                cstatus[i] = 0;
            }
            else if(insidepolygon(robberch, citizens[i], 1)) {
                cstatus[i] = 1;
            }
        }
        
        cout << "Data set " << t++ << ":\n";
        for(int i = 0; i < o; i++) {
            cout << "     Citizen at (" << citizens[i].x << "," << citizens[i].y << ") is ";
            if(!cstatus[i]) {
                cout << "safe.\n";
            }
            if(cstatus[i] == 1) {
                cout << "robbed.\n";
            }
            if(cstatus[i] == -1) {
                cout << "neither.\n";
            }
        }
        cout << "\n";
    }

    return 0;
}
