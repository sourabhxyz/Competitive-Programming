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

void retsign(double num) {
    if(num + EPS < 0) cout << " - ";
    else cout << " + ";
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(3);
    point a, b, c;
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
        double ab = compdist(a, b);
        double bc = compdist(b, c);
        double ac = compdist(a, c);
        point abv = getvec(a, b);
        point acv = getvec(a, c);
        point mab = a + scale(abv, 0.5);
        point mac = a + scale(acv, 0.5);
        double sloperac = getpslope(a, c);
        double sloperab = getpslope(a, b);
        line pac = getLine(mac, sloperac);
        line pab = getLine(mab, sloperab);
        point center = Intersect(pac, pab);
        double radius = compdist(center, a);
        if(center.x + EPS > 0 && center.y < 0)
            cout << "(x - " << center.x << ")^2 + (y + " << abs(center.y) << ")^2 = " << radius <<"^2\n";
        else if(center.x < 0 && center.y + EPS > 0)
            cout << "(x + " << abs(center.x) << ")^2 + (y - " << center.y << ")^2 = " << radius <<"^2\n";
        else if(center.x + EPS > 0 && center.y + EPS > 0)
            cout << "(x - " << abs(center.x) << ")^2 + (y - " << abs(center.y) << ")^2 = " << radius <<"^2\n";
        else
            cout << "(x + " << abs(center.x) << ")^2 + (y + " << abs(center.y) << ")^2 = " << radius <<"^2\n";
        double coeffx = (-1 * 2 * center.x), coeffy = (-2 * center.y), cons = (center.x * center.x + center.y * center.y - radius * radius);
        cout << "x^2 + y^2"; retsign(coeffx); cout << abs(coeffx) << "x"; retsign(coeffy); cout << abs(coeffy) << "y"; retsign(cons); cout << abs(cons) << " = 0\n\n"; //cout << center.x << " " << center.y << "\n";
    }
}
