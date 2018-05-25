#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    ll n, m;
    cin >> n >> m;
    if (n <= m) {
        cout << (n + (n - 1) - 1);
    } else {
        cout << (m + (m - 1));
    }
}