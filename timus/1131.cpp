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
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (k >= n) {
        int p2 = 1;
        int ans = 0;
        while (p2 < n) {
            p2 *= 2;
            ans++;
        }
        cout << ans << "\n";
        return 0;
    }
    int cur = 0;
    int p2 = 1;
    while (p2 < k) {
        p2 *= 2;
        cur++;
    }
    n -= p2;
    cout << (cur + (n + k - 1) / k);


}
