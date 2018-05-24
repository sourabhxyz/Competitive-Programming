#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        if (k == 1) {
            if (i) cout << " ";
            cout << "1";
        } else {
            k--;
            k = (1 + 8 * k);
            if (abs(sqrt(k) - (int)(sqrt(k))) < eps) {
                int nn = (-1 + sqrt(k) + eps);
                if (nn & 1) {
                    if (i) cout << " ";
                    cout << "0";
                } else {
                    if (i) cout << " ";
                    cout << "1";
                }
            } else {
                if (i) cout << " ";
                cout << "0";
            }
        }
    }
}

