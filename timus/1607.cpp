#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c <= a) {
        cout << a;
        return 0;
    }
    ll k = ceil((double)(c - a) / (b + d));
    k--;
    if ((a + (k + 1) * b <= c - k * d)) k++;
    cout << max(a + k * b, c - k * d);
}