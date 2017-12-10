#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-7
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

vector<point> data;

double dvac(int low, int high) {
    if(low < high) {
        if(low == high - 1) {
            return max(data[high].x - data[low].x, abs(data[high].y - data[low].y));
        }
        int mid = (low + high) / 2;
        double d1 = dvac(low, mid);
        double d2 = dvac(mid + 1, high);
        double dp = min(d1, d2);
        double d3 = INF;
        for(int i = mid; i >= low; i--) {
            double temp = dist(point(data[i].x, 0), point(data[mid].x, 0));
            if(temp > dp - EPS) break;
            for(int j = mid + 1; j <= high; j++) {
                double temp2 = dist(point(data[i].x, 0), point(data[j].x, 0));
                if(temp2 > dp - EPS) break;
                d3 = min(d3, max(data[j].x - data[i].x, abs(data[j].y - data[i].y)));
            }
        }
        return min(dp, d3);
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(4);
    int n;
    while(cin >> n) {
        data.clear();
        for(int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            data.push_back(point(x, y));
        }
        sort(data.begin(), data.end());
        double ans = dvac(0, n - 1);
        cout << ans << "\n";
    }
    return 0;
}
