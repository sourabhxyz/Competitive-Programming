#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
#define inf 1e14
#define end en

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(0);
    ll n;
    cin >> n;
    cout << ((n * (n + 1) * (2 * n + 1)) + (3 * n * (n + 1))) / 4;
}