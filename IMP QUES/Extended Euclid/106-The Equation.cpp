#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll a, b, c, xmin, xmax, ymin, ymax, d;
void extendedEuclid(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    extendedEuclid(b, a % b, x, y);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

ll solve() {
    if (xmax < xmin || ymax < ymin) return 0;
    if (a == 0 and b == 0) {
        if (c == 0) {
            return (xmax - xmin + 1LL) * (ymax - ymin + 1LL);
        } else return 0LL;
    }
    if (a == 0) {
        if (c % b == 0 and ((c / b) >= ymin and (c / b) <= ymax)) {
            return (xmax - xmin + 1);
        } else return 0LL;
    }
    if (b == 0) {
        if (c % a == 0 and ((c / a) >= xmin and (c / a) <= xmax)) {
            return (ymax - ymin + 1);
        } else return 0LL;
    }
    ll x0, y0;
    extendedEuclid(abs(a), abs(b), x0, y0);
    if (a < 0) x0 *= -1;
    if (b < 0) y0 *= -1;
    if (c % d != 0) return 0LL;
    x0 *= c / d;
    y0 *= c / d;
    ll n1, n2;
    if (b < 0) {
        n1 = (ll)floor((double) d / b * (xmin - x0));
        n2 = (ll)ceil((double) d / b * (xmax - x0));
    } else {
        n1 = (ll)ceil((double) d / b * (xmin - x0));
        n2 = (ll)floor((double) d / b * (xmax - x0));
    }
    if (n1 > n2) swap(n1, n2);
    ll n3, n4;
    if (a > 0) {
        n3 = (ll)floor((double) d / a * (y0 - ymin));
        n4 = (ll)ceil((double) d / a * (y0 - ymax));
    } else {
        n3 = (ll)ceil((double) d / a * (y0 - ymin));
        n4 = (ll)floor((double) d / a * (y0 - ymax));
    }
    if (n3 > n4) swap(n3, n4);
    ll rx = min(n2, n4);
    ll lx = max(n1, n3);
    if (rx < lx) return 0;
    return ((rx - lx)) + 1;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cin >> a >> b >> c >> xmin >> xmax >> ymin >> ymax;
    c *= -1;
    cout << solve() << "\n";
    return 0;
}