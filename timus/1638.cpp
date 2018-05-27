#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
#define inf 1000000000
const ll m = 1000000007;
#define end en
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    int vth, bcth, start, end;
    cin >> vth >> bcth >> start >> end;
    int ans = 0;
    if (end > start) {
        ans += (end - start - 1) * (vth + (2 * bcth));
        ans += (2 * bcth);
    } else if (end < start) {
        ans += (start - end + 1) * (vth + (2 * bcth));
        ans -= (2 * bcth);
    } else {
        ans = vth;
    }
    cout << ans << "\n";
}