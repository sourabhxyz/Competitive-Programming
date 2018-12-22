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
void solve () {
    string s;
    string orig;
    cin >> s;
    orig = s;
    for (int i = 0, n = s.size (), k = n - 1; i <= k; i++, k--) {
        s[k] = s[i];
    }
    int i = (s.size() - 1) / 2, j = s.size() - 1 - i;
    while (s < orig and i >= 0 and j < s.size()) {
        char old = s[i];
        if (old != '9') {
            s[i] = old + 1;
            s[j] = old + 1;
            for (int iter = i + 1; iter < j; iter++) {
                s[iter] = '0';
            }
        }
        i--;
        j++;
    }
    cout << s << "\n";
}
int main () {
#ifdef LOCAL
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve ();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}