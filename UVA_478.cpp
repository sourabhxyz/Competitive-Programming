#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-7

struct point {
    double x, y;
    point() {}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
};

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

struct figure{
    char type;
    point ul, lr;
    point center;
    double radius;
    point a, b, c;
    figure() {ul = lr = a = b = c = center = point(0, 0);
        radius = 0;
        type = '0';
    }
};

struct line {
    double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } }

vector<figure> data;

double poswrtline(point a, line l) { //returns true if the point is above the line and false o/w.
    double ans = l.a * a.x + l.b * a.y + l.c;
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    char ch;
    vector<point> tocheck;
    while(cin >> ch && ch != '*') {
        if(ch == 'r') {
            point ul, lr;
            cin >> ul.x >> ul.y >> lr.x >> lr.y;
            figure rect;
            rect.type = 'r';
            rect.ul = ul; rect.lr = lr;
            data.push_back(rect);
        }
        if(ch == 'c') {
            point center;
            cin >> center.x >> center.y;
            double radius;
            cin >> radius;
            figure circle;
            circle.center = center;
            circle.radius = radius;
            circle.type = 'c';
            data.push_back(circle);
        }
        if(ch == 't') {
            point a, b, c;
            cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
            figure triangle;
            triangle.type = 't';
            triangle.a = a;
            triangle.b = b;
            triangle.c = c;
            data.push_back(triangle);
        }
    }
    double x, y;
    while(cin >> x >> y && (abs(x - 9999.9) > EPS || (abs(y - 9999.9) > EPS))) {
        tocheck.push_back(point(x, y));
    }
    for(int i = 0; i < tocheck.size(); i++) {
        bool found = false;
        for(int j = 0; j < data.size(); j++) {
            figure ths = data[j];
            point tochk = tocheck[i];
            if(ths.type == 'r') {
                double xx = tochk.x, yy = tochk.y;
                if(xx > ths.ul.x && xx < ths.lr.x && yy < ths.ul.y && yy > ths.lr.y) {
                    cout << "Point " << i + 1 << " is contained in figure " << j + 1 << "\n";
                    found = true;
                }
            }
            if(ths.type == 'c') {
                point center = ths.center;
                double radius = ths.radius;
                if(dist(center, tochk) < radius) {
                    cout << "Point " << i + 1 << " is contained in figure " << j + 1 << "\n";
                    found = true;
                }
            }
            if(ths.type == 't') {
                line ab, bc, ca;
                pointsToLine(ths.a, ths.b, ab); pointsToLine(ths.b, ths.c, bc); pointsToLine(ths.c, ths.a, ca);
                bool ch1 = false;
                double pwbc = poswrtline(tochk, bc);
                double twbc = poswrtline(ths.a, bc);
                if((pwbc < 0 && twbc < 0) || (pwbc > 0 && twbc > 0)) {
                    ch1 = true;
                }
                //double pwab = poswrtline(tochk, ca);
                //double twab = poswrtline(ths.b, ca);
                bool ch2 = false;
                pwbc = poswrtline(tochk, ca);
                twbc = poswrtline(ths.b, ca);
                if((pwbc < 0 && twbc < 0) || (pwbc > 0 && twbc > 0)) {
                    ch2 = true;
                }
                bool ch3 = false;
                pwbc = poswrtline(tochk, ab);
                twbc = poswrtline(ths.c, ab);
                if((pwbc < 0 && twbc < 0) || (pwbc > 0 && twbc > 0)) {
                    ch3 = true;
                }
                if(ch1 && ch2 && ch3) {
                    cout << "Point " << i + 1 << " is contained in figure " << j + 1 << "\n";
                    found = true;
                }
            }
        }
        if(!found) {
            cout << "Point " << i + 1 << " is not contained in any figure\n";
        }
    }
    return 0;
}
