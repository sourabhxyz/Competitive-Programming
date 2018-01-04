#include<bits/stdc++.h>

using namespace std;
#define EPS 1e-7

int n, a;
struct point {
    double x, y;
    point() {}
    point(double u, double v) {
        x = u; y = v;
    }
};
vector<point> data;
double compdist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

vector<point> check(point center, vector<point> &from) {
    vector<point> in;
    for(int i = 0; i < from.size(); i++) {
        point curr = from[i];
        double dist = compdist(curr, center);
        if(dist < (double)a + EPS) {
            in.push_back(from[i]);
        }
    }
    return in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(5);
    while(cin >> n >> a && (n || a)) {
        data.clear();
        data.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> data[i].x >> data[i].y;
        }
        vector<point> ina = check(point(0, 0), data);
        vector<point> inab = check(point((double)a, 0), ina);
        vector<point> inabc = check(point((double)a, (double)a), inab);
        vector<point> inabcd = check(point(0, (double)a), inabc);
        double m = inabcd.size();
        double req = m * a * a;
        req /= n;
        cout << req << "\n";
    }
}
