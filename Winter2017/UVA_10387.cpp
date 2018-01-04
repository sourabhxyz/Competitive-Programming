#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
    double a, b, s, m, n;
    double pi = 2 * acos(0);
    while(cin >> a >> b >> s >> m >> n && (a + b + s + m + n) != 0) {
        double v = (sqrt(m * m * a * a + n * n * b * b) / s);
        double theta = atan((b * n) / (a * m));
        cout << theta * 180 / pi << " " << v << "\n";
    }
    return 0;
}
