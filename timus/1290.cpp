#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
    #pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
#endif
typedef long long int ll;
typedef pair<int, int> ii;
const int inf = 100000000;
const double eps = 1e-12;
void solve () {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "";
        return;
    }
    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    int cnt[n + 10];
    memset (cnt, 0, sizeof (cnt));
    int tot = 0;
    int k = 1;
    for (int i = n - 1; i > 0; i--, k++) {
        cnt[k] = a[i] - a[i - 1];
        tot += cnt[k];
    }
    cnt[k] = a[0] - 1;
    tot += cnt[k];
    cnt[n]++;
    tot++;
    vector<int> ans;
    ans.push_back(tot);
    for (int i = n; i > 0; i--) {
        cnt[i - 1] += cnt[i];
    }
    for (int i = 2; i <= n; i++) {
        if (cnt[i] != 0)
            ans.push_back(cnt[i]);
    }
    for (auto &v: ans) {
        cout << v << " ";
    }

}
int main ( ) {
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