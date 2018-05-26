#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-9;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(10);
    int a, b;
    cin >> a >> b;
    cout << max((40 * 3 + (b - 40) * 2), 39 + 2 * a);
}