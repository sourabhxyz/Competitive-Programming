#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
    #pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
#endif
typedef long long int ll;
typedef pair<int, int> ii;
const int inf = 1000000;
const double eps = 1e-12;
#define itn int
#define tmep temp

void solve () {
    ll n, k;
    cin >> n >> k;
    ll ans = 100000000000000;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll a = i;
            ll b = n / i;
            ll x1 = b + k * a;
            if (x1 / k == a and x1 % k == b) {
                ans = min (ans, x1);
            }
            ll x2 = a + k * b;
            if (x2 / k == b and x2 % k == a) {
                ans = min (ans, x2);
            }
        }
    }
    cout << ans << "\n";
}

int main () {
#ifdef LOCAL
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
#endif
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve ();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}