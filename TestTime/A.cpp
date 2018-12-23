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
    cin >> s;
    bool isPal[s.size()][s.size()];
    for (int i = 0; i < s.size(); i++) {
        isPal[i][i] = true;
        for (int j = i + 1; j < s.size(); j++) {
            isPal[i][j] = (i + 1 >= j - 1 or s[i] == s[j]) and isPal[i + 1][j - 1];
        }
    }
    int dp[4005];
    memset (dp, inf, sizeof (dp));
    dp[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size (); j++) {
            if (isPal[i][j]) {
                dp[j] = min (dp[j], dp[i - 1] + 1);
            }
        }
    }
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