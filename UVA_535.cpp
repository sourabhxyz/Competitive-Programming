#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-7
map<string, pair<double, double> > data;
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
    double pi = 2 * acos(0);
    double r = 6378;
    string line;
    while(cin >> line && line != "#") {
        double theta, phi;
        cin >> theta >> phi;
        data[line].first = theta * pi / 180; data[line].second = phi * pi / 180;
    }
    string a, b;
    while(cin >> a >> b && (a != "#" || b != "#")) {
        cout << a << " - " << b << "\n";
        if(data.find(a) == data.end() || data.find(b) == data.end()) {
            cout << "Unknown\n";
            continue;
        }
        double theta1 = data[a].first, phi1 = data[a].second;
        point aa = point(cos(theta1) * cos(phi1), cos(theta1) * sin(phi1), sin(theta1));
        double theta2 = data[b].first, phi2 = data[b].second;
        point bb = point(cos(theta2) * cos(phi2), cos(theta2) * sin(phi2), sin(theta2));
        double ab = dist(aa, bb);
        ab *= r;
        double theta = acos((r * r + r * r - ab * ab) / (2 * r * r));
        cout << round(r * theta) << " km\n";
    }
    return 0;
}
