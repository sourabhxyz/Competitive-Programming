#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-7

struct point {
    double x, y, z;
    point() {}
    point(double xx, double yy, double zz) {
        x = xx; y = yy; z = zz;
    }
};

double dist(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int tc;
    cin >> tc;
    cout << fixed << setprecision(0);
    double pi = 2 * acos(0);
    double r = 6371009;
    while(tc--) {
        double theta1, phi1, theta2, phi2;
        cin >> theta1 >> phi1 >> theta2 >> phi2;
        theta1 *= pi / 180; phi1 *= pi / 180; theta2 *= pi / 180; phi2 *= pi / 180;
        point aa = point(cos(theta1) * cos(phi1), cos(theta1) * sin(phi1), sin(theta1));
        point bb = point(cos(theta2) * cos(phi2), cos(theta2) * sin(phi2), sin(theta2));
        double ab = dist(aa, bb);
        ab *= r;
        double theta = acos((r * r + r * r - ab * ab) / (2 * r * r));
        double gcd = r * theta;
        cout << abs(gcd - ab) << "\n";
    }
    return 0;
}
