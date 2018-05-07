/*Follows Salix idea: https://math.stackexchange.com/questions/256100/how-can-i-find-the-points-at-which-two-circles-intersect */
/*Judges I/O is messed up, I believe my solution is correct*/

#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define EPS2 5e-5
double PI = 2 * acos(0);
#define INF 10000000000

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    cout << fixed << setprecision(3);
    int t;
    double x1, x2, y1, y2, r1, r2;
    while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2) {
        double centerdist = dist(vec(x1, y1), vec(x2, y2));
        if(r1 > EPS and centerdist < EPS and abs(r1 - r2) < EPS) {
            cout << "THE CIRCLES ARE THE SAME\n";
            continue;
        }
        if(r1 < EPS and r2 < EPS and centerdist < EPS) {
            cout << "(" << x1 + EPS2 << "," << y1 + EPS2 << ")\n";
            continue;
        }
        if(centerdist < EPS) {
            cout << "NO INTERSECTION\n";
            continue;
        }
        if(centerdist > r1 + r2 + EPS) {
            cout << "NO INTERSECTION\n";
            continue;
        }
        if(centerdist + r2 < r1 - EPS || centerdist + r1 < r2 - EPS) {
            cout << "NO INTERSECTION\n";
            continue;
        }
        vec c1 = vec(x1, y1), c2 = vec(x2, y2);
        vec d = c2 - c1;
        double absd = abs(d);
        double c1p = (absd * absd + (r1 * r1) - (r2 * r2)) / (2 * absd);
        double absh = sqrt(r1 * r1 - c1p * c1p);
        vec ud = d / absd;
        vec pd = perp(ud);
        vec p = c1 + (ud * c1p);
        vec h = pd * absh;
        vector<vec> ans;
        ans.push_back(vec(p - h));
        ans.push_back(vec(p + h));
        sort(ans.begin(), ans.end());
        if(absh < EPS) { //only one solution
            cout << "(" << p.x + EPS2 << "," << p.y + EPS2 << ")\n";
            continue;
        }
        cout << "(" << ans[0].x + EPS2 << "," << ans[0].y + EPS2 << ")";
        cout << "(" << ans[1].x + EPS2 << "," << ans[1].y + EPS2 << ")\n";
    }
    return 0;
}