#include<bits/stdc++.h>

using namespace std;
#define EPS 1e-7
#define INF 1000000000
struct point {
    double x, y;
    point() {}
    point(double u, double v) {
        x = u; y = v;
    }
    point operator + (const point &other) const {
        point temp;
        temp = point(x + other.x, y + other.y);
        return temp;
    }
};
vector<point> data;
double compdist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}
point getvec(point a, point b) {
    return point(b.x - a.x, b.y - a.y);
}
point scale(point give, double scale) {
    give.x *= scale;
    give.y *= scale;
    return give;
}
double getpslope(point a, point c) {
    double sloperac;
    if(abs(a.x - c.x) < EPS) {
        sloperac = 0;
    }
    else if(abs(a.y - c.y) < EPS){
        sloperac = INF;
    }
    else {
        sloperac = (-1) * (c.x - a.x) / (c.y - a.y);
    }
    return sloperac;
}
struct line {
    double a, b, c;
};
line getLine(point from, double slope) {
    line toret;
    if(slope == INF) {
        toret.a = 1; toret.b = 0; toret.c = -1 * from.x;
    }
    else if(abs(slope) < EPS) {
        toret.a = 0; toret.b = 1; toret.c = -1 * from.y;
    }
    else {
        toret.a = (-1 * slope);
        toret.b = 1;
        toret.c = ((slope * from.x) - from.y);
    }
    return toret;
}

point Intersect(line l1, line l2) {
    point p;
// solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(3);
    double a, b, c;
    while(cin >> a >> b >> c) {
        double s = (a + b + c) / 2;
        if(abs(s) < EPS) {
            cout << "The radius of the round table is: 0.000" << "\n";
            continue;
        }
        double area = s * (s - a);
        area = sqrt(area);
        double temp = (s - b) * (s - c);
        temp = sqrt(temp);
        area *= temp;
        double radius = area / s;
        cout << "The radius of the round table is: " << radius << "\n";
    }

}
