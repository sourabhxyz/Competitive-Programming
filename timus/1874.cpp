#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

double a, b;
double f(double ph) {
    double theta = asin((-a * cos(ph) + sqrt(a * a * cos(ph) * cos(ph) + (2 * b * b))) / (2 * b));
    return ((b * b * sin(theta) * cos(theta) / 2) + ((2 * b * cos(theta) + a * sin(ph)) * a * cos(ph) / 2));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(10);
    cin >> a >> b;
    double phl = 0, phr = pi / 2;
    for (int i = 0; i < 200; i++) {
        double m1 = phl + (phr - phl) / 3;
        double m2 = phr - (phr - phl) / 3;
        if (f(m1) < f(m2)) {
            phl = m1;
        } else {
            phr = m2;
        }
    }
    cout << f((phl + phr) / 2);
}