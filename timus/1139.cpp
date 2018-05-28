#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
typedef pair<int, int> ii;
#define inf 1e8
#define itn int
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  freopen("inc.txt", "r", stdin);
    //  freopen("outc.txt", "w", stdout);
    // cout << fixed << setprecision(0);
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << x - 1 << "\n";
        return 0;
    }
    x--; y--;
    itn d = gcd(x, y);
    x /= d; y /= d;
    cout << d * (x + y - 1) << "\n";

}
