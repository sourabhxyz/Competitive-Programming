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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(4);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    point a, b, c;
    int t;
    cin >> t;
    while(t--) {
        double radius;
        cin >> radius;
        double m1, n1, m2, n2, m3, n3;
        cin >> m1 >> n1 >> m2 >> n2 >> m3 >> n3;
        //cout << m1 * m2 * m3 << " " << n1 * n2 * n3 << "\n";
        double k1 = m2 * m1 / (n2 * n1), k2 = m2 / n2, k3 = 1;
        double s = (k1 + k2 + k3);
        double area = s * (s - k1 - k2) * (s - k2 - k3) * (s - k3- k1);
        area = sqrt(area);
        double abys = area / s;
        double z = radius / abys;
        double x = k1 * z;
        double y = k2 * z;
        area = z * z * area;
        cout << area << "\n";
    }
    return 0;
}
