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
    int x, y, c;
    cin >> x >> y >> c;
    int lo = 0, hi = x;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int b = (c - mid);
        if (b >= 0 and b <= y) {
            cout << mid << " " << b;
            return 0;
        } else if (b < 0) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << "Impossible";
}