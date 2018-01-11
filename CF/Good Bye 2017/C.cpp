#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
#define inf 100000000;
const double EPS = 1e-8;
const double eps = EPS;
const double PI = 2 * acos(0);

void solve() {
    int n;
    double r;
    cin >> n >> r;
    vector<double> x(n);
    vector<double> y(n);
//    double ny = r;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        y[i] = r;
        for (int j = 0; j < i; j++) {
            if (abs(x[j] - x[i]) > 2 * r + eps) continue;
            y[i] = max(y[i], y[j] + sqrt(4 * r * r - (x[j] - x[i]) * (x[j] - x[i])));
        }
        if (i) cout << " ";
        cout << y[i];
    }
    cout << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
//    freopen("ina.txt", "r", stdin);
//    freopen("outa.txt", "w", stdout);
    solve();
    return 0;
}
