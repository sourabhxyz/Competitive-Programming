#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    if (n > 2 or n == 0) {
        cout << "-1";
        return 0;
    }
    for (int a = 1; a <= 100; a++) {
        for (int b = a + 1; b <= 100; b++) {
            double res = pow(a, n) + pow(b, n);
            res = pow(res, 1.0 / n);
            if (abs(res - (int)(res + eps)) < eps) {
                int c = (int)(res + eps);
                if (c <= 100 and c >= 1) {
                    cout << a << " " << b << " " << c;
                    return 0;
                }
            }
        }
    }
    cout << "-1";
}