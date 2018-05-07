#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;
const double pi = 2 * acos(0);
const double PI = pi;
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
    bool operator < (const vec &other) const{
        if(abs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const vec &other) const{
        return (abs(x - other.x) < EPS && abs(y - other.y) < EPS);
    }
};

vec perp(vec a) {
    return vec(-a.y, a.x);
}
double abs(vec a) {
    return sqrt(a.x * a.x + a.y * a.y);
}
double dist(vec a, vec b) {
    return hypot(a.x - b.x, a.y - b.y);
}

struct line{
    double a, b, c;
};

void vecsToLine(vec p1, vec p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }
bool areSame(line l1, line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

bool areIntersect(line l1, line l2, vec &p) {
    if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}
struct linesegment{
    vec a, b;
    line l;
    linesegment() {}
    linesegment(vec aa, vec bb) {
        vecsToLine(aa, bb, l);
        a = aa; b = bb;
    }
};
bool lieson(linesegment l, vec p) {
    return (p.x > min(l.a.x, l.b.x) - EPS and p.x < max(l.a.x, l.b.x) + EPS and p.y > min(l.a.y, l.b.y) - EPS and p.y < max(l.a.y, l.b.y) + EPS);
}
bool intersectLineSegWithLine(linesegment l1, line l2) {
    vec p;
    return (areIntersect(l1.l, l2, p) and lieson(l1, p));
}
line abcToLine(double a, double b, double c) {
     if (abs(b) < EPS) {
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

double dot(vec a, vec b)
{ return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v)
{ return v.x * v.x + v.y * v.y; }
double angle(vec a, vec o, vec b)
{ // returns angle aob in rad
    vec oa = a - o, ob = b - o;
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(vec p, vec q, vec r) {
    return cross(q - p, r - q) > 0; }
struct circle {
    vec c; double r;
};
double sq(vec v) {
    return v.x * v.x + v.y * v.y;
}
vec pivot;
bool polarsort(vec a, vec b) {
    return cross(a - pivot, b - pivot) > 0;
}
bool circleCircle(vec c1, double r1, vec c2, double r2, pair<vec,vec> &out) {
    vec d = c2 - c1;
    double centerdist = abs(d);
    if(centerdist < EPS and abs(r1 - r2) < EPS) {
        cout << "1\n";
        exit(0);
    }
    if(centerdist < EPS) {
        cout << "1\n";
        exit(0);
    }
    if(centerdist > r1 + r2 + EPS) {
        return false;
    }
    if(centerdist + r2 < r1 - EPS || centerdist + r1 < r2 - EPS) {
        return false;
    }
    double absd = abs(d);
    double c1p = (absd * absd + (r1 * r1) - (r2 * r2)) / (2 * absd);
    if (r1 * r1 - c1p * c1p < -EPS) return false;
    double absh = sqrt(r1 * r1 - c1p * c1p);
    vec ud = d / absd;
    vec pd = perp(ud);
    vec p = c1 + (ud * c1p);
    vec h = pd * absh;
    if (absh < EPS) {
        return false;
    }
    vector<vec> ans;
    ans.push_back(p + h);
    ans.push_back(p - h);
    sort(ans.begin(), ans.end(), polarsort);
    out.first = ans[0]; out.second = ans[1];
    return true;
}
/*vector<pair<double, double> > intervalCover(vector<pair<double, double> > data) {
    sort(data.begin(), data.end());
    int j;
    for (int i = 0; i < data.size(); i = j) {
        for (j = i + 1; j < data.size(); j++) {
            if (data[j])
        }
    }
};*/
bool onOrInside(vec p, vec c, double r) {
    return (abs(p - c) < r + EPS);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("inb.txt", "r", stdin);
    freopen("outb.txt", "w", stdout);
    circle master;
    int temp;
    vector<pair<double, int> > a;
    cin >> master.c.x >> master.c.y >> master.r >> temp;
    master.r *= temp;
    double prob = 1 / (2 * pi);
    int n;
    cin >> n;
    pivot = master.c;
    vector<pair<double, double> > data;
    vector<pair<double, double> > final;
    double test = 0;
    for (int i = 0; i < n; i++) {
        circle temp;
        cin >> temp.c.x >> temp.c.y >> temp.r;
        pair<vec, vec> isects;
        if (abs(master.r) < EPS) {
            if (onOrInside(master.c, temp.c, temp.r))
            cout << "1\n";
            return 0;
        } else if (circleCircle(master.c, master.r, temp.c, temp.r, isects)) {
//            cout << isects.first.x << " " << isects.first.y << " " << isects.second.x << " " << isects.second.y << "\n";
            double two = atan2(isects.second.y, isects.second.x);
            double one = atan2(isects.first.y, isects.first.x);
/*            if (quadrant(a) == 1 and quadrant(b) == 1) {
                if (two > one) {

                }
            }*/
            if (one < 0 and two > 0) {
                test += two - one;
            } else if (one > 0 and two < 0) {
                test += 2 * pi - one + two;
            } else {
                test += two - one;
            }
            double angL = one;
            double angR = two;
            if (angL < 0) {
                a.push_back(make_pair(angL + 2 * PI, 1));
                a.push_back(make_pair(2 * PI, -1));
                a.push_back(make_pair(0.0, 1));
                a.push_back(make_pair(angR, -1));
            } else if (angR > 2 * PI) {
                a.push_back(make_pair(angL, 1));
                a.push_back(make_pair(2 * PI, -1));
                a.push_back(make_pair(0.0, 1));
                a.push_back(make_pair(angR - 2 * PI, -1));
            } else {
                a.push_back(make_pair(angL, 1));
                a.push_back(make_pair(angR, -1));
            }
            data.push_back({min(one, two), max(one, two)});

//            cout << two * 180 / pi << " " << one * 180 / pi << "\n";
        }
    }
    sort(a.begin(), a.end());
    cout << test / (2 * pi) << "\n";
    double last = 0;
    int c = 0;
    double ans = 0;

    for (auto& p : a) {
        if (c > 0) {
            ans += p.first - last;
        }
        c += p.second;
        last = p.first;
    }

//    ans /= 2 * PI;
   /*
    double ans = 0;
    double prevlow = 0, prevhigh = 0;
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++) {
        double lo = data[i].first, hi = data[i].second;
        if (lo > prevlow) {
            ans += hi - lo;
            prevlow = lo; prevhigh = hi;
        } else if (hi > prevhigh){
            ans += hi - prevhigh;
            prevlow = prevhigh; prevhigh = hi;
        }
    }*/
    cout << fixed << setprecision(9) << ans * prob << "\n";
    return 0;
}