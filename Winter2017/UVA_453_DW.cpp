/*Follows Salix idea: https://math.stackexchange.com/questions/256100/how-can-i-find-the-points-at-which-two-circles-intersect */
/*Judges I/O is messed up, I believe my solution is correct*/

#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define EPS2 5e-5
double PI = 2 * acos(0);
#define INF 10000000000

struct point {
    double x, y;
    point () {}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
    bool operator < (const point &other) const{
        if(abs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point &other) const{
        return (abs(x - other.x) < EPS && abs(y - other.y) < EPS);
    }
};

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(3);
    int t;
    double x1, x2, y1, y2, r1, r2;
    while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2) {
        double centerdist = dist(point(x1, y1), point(x2, y2));
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
        double d = centerdist;
        double l = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
        double h = sqrt(r1 * r1 - l * l);
        if(abs(h) < EPS) { //only one solution
            double x = ((l / d) * (x2 - x1) + (h / d) * (y2 - y1) + x1);
            double y = ((l / d) * (y2 - y1) - (h / d) * (x2 - x1) + y1);
            cout << "(" << x + EPS2 << "," << y + EPS2 << ")\n";
            continue;
        }
        double x = ((l / d) * (x2 - x1) + (h / d) * (y2 - y1) + x1);
        double y = ((l / d) * (y2 - y1) - (h / d) * (x2 - x1) + y1);
        vector<point> ans;
        ans.push_back(point(x, y));
        x = ((l / d) * (x2 - x1) - (h / d) * (y2 - y1) + x1);
        y = ((l / d) * (y2 - y1) + (h / d) * (x2 - x1) + y1);
        ans.push_back(point(x, y));
        sort(ans.begin(), ans.end());
        cout << "(" << ans[0].x + EPS2 << "," << ans[0].y + EPS2 << ")";
        cout << "(" << ans[1].x + EPS2 << "," << ans[1].y + EPS2 << ")\n";
    }
    return 0;
}
