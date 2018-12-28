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
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    int bcnt[32];
    memset (bcnt, 0, sizeof (bcnt));
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            bcnt[i]++;
            cnt++;
        }
    }
    for (int i = 31; i >= 1; i--) {
        if (cnt < k) {
            bcnt[i - 1] += 2 * bcnt[i];
            cnt += bcnt[i];
            bcnt[i] = 0;
        } else break;
    }

    for (int i = 0; i <= 30; i++) {
        while (cnt > k and bcnt[i] >= 2) {
            bcnt[i] -= 2;
            bcnt[i + 1]++;
            cnt--;
        }
    }
    if (cnt != k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
//    int powers[32];
//    for (int i = 0; i <= 31; i++) {
//
//    }
    for (int i = 0; i <= 31; i++) {
        while (bcnt[i]) {
            cout << (1 << i) << " ";
            bcnt[i]--;
        }
    }

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