#include<bits/stdc++.h>

using namespace std;

#define eps 1e-7
struct point{
    double x, y;
    point() {}
    point(double u, double v) {
        x = u; y = v;
    }
};

struct rectangle{
    point a, b, c, d;
    rectangle(point u, point v, point z, point w) {
        a = u; b = v; c = z; d = w;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(6);
    char c;
    vector<rectangle> data;
    while(cin >> c && c == 'r') {
        point ul, lr;
        cin >> ul.x >> ul.y >> lr.x >> lr.y;
        data.push_back(rectangle(ul, point(ul.x, lr.y), lr, point(lr.x, ul.y)));
    }
    double x, y;
    vector<point> totest;
    while(cin >> x >> y && (abs(x - 9999.9) > eps || abs(y - 9999.9) > eps)) {
        totest.push_back(point(x, y));
    }
    for(int i = 0; i < totest.size(); i++) {
        bool found = false;
        for(int j = 0; j < data.size(); j++) {
            point tocheck = totest[i];
            rectangle fig = data[j];
            if(tocheck.y > fig.b.y + eps && tocheck.y + eps < fig.a.y && tocheck.x - eps > fig.a.x && tocheck.x + eps < fig.c.x) {
                found = true;
                cout << "Point " << i + 1 << " is contained in figure " << j + 1 << "\n";
            }
        }
        if(!found) {
            cout << "Point " << i + 1 << " is not contained in any figure\n";
        }
    }
    return 0;
}
