#include<bits/stdc++.h>

using namespace std;

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

double tria(point a, point b, point c) {
    double area = (a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x) / 2.0;
    return abs(area);
}

bool isinside(point tochk, point a, point b, point c, double area) {
    double area_ = tria(a, b, tochk);
    area_ += tria(a, tochk, c);
    area_ += tria(tochk, b, c);
    return (area_ <= area + EPS)? true : false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << fixed << setprecision(2);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    point a, b, c;
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
        double xmin = 100, ymin = 100, xmax = 0, ymax = 0;
        if(a.x + b.x + c.x + a.y + b.y + c.y < EPS) break;
        xmin = min(xmin, min(a.x, min(b.x, c.x)));
        ymin = min(ymin, min(a.y, min(b.y, c.y)));
        xmax = max(xmax, max(a.x, max(b.x, c.x)));
        ymax = max(ymax, max(a.y, max(b.y, c.y)));
        xmin = ceil(xmin), xmax = floor(xmax), ymin = ceil(ymin), ymax = floor(ymax);
        int xxmin = max((int)xmin, 1), xxmax = min((int)xmax, 99), yymin = max((int)ymin, 1), yymax = min((int)ymax, 99);
        int cnt = 0;
        for(int i = xxmin; i <= xxmax; i++) {
            for(int j = yymin; j <= yymax; j++) {
                double area = tria(a, b, c);
                if(isinside(point(i, j), a, b, c, area))
                    cnt++;
            }
        }
        cout << setw(4) << cnt << "\n";
    }
    return 0;
}
