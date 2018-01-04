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

vector<pair<double, double> > data;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);
    double pi = 2 * acos(0);
    double r = 1;
    string line;
    int n;
    while(cin >> n) {
        data.clear();
        for(int i = 0; i < n; i++) {
            double theta, phi;
            cin >> theta >> phi;
            data.push_back(make_pair(theta * pi / 180, phi * pi / 180));
        }
        double mn = 10000000000;
        int index;
        for(int i = 0; i < data.size(); i++) {
            double mx = -1;
            for(int j = 0; j < data.size(); j++) {
                if(i == j) continue;
                double theta1 = data[i].first, phi1 = data[i].second;
                point aa = point(cos(theta1) * cos(phi1), cos(theta1) * sin(phi1), sin(theta1));
                double theta2 = data[j].first, phi2 = data[j].second;
                point bb = point(cos(theta2) * cos(phi2), cos(theta2) * sin(phi2), sin(theta2));
                double ab = dist(aa, bb);
                ab *= r;
                double theta = acos((r * r + r * r - ab * ab) / (2 * r * r));
                if(mx < theta) {
                    mx = theta;
                }
            }
            if(mn > mx - 1e-7) {
                mn = mx;
                index = i;
            }
        }
        cout << data[index].first * 180 / pi << " " << data[index].second * 180 / pi << "\n";
    }

    return 0;
}
