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
    char c;
    int cnt = 0;
    while (cin >> c) cnt++;
    ll res = 1;
    while (n > 0) {
        res *= (ll)n;
        n -= cnt;
    }
    cout << res << "\n";
}