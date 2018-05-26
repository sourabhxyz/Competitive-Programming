#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
const double pi = 3.1415926535;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int v, a;
    double k;
    cin >> v >> a >> k;
    if (v == 0) {
        cout << "0.00";
        return 0;
    }
    if (a == 90) {
        cout << "0.00";
        return 0;
    } else if (a == 0) {
        cout << "0.00";
        return 0;
    }
    double base = ((double)v * v) * sin(2 * a * pi / 180) / 10;
    cout << base * (k) / (k - 1) << "\n";
}