#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
    #pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
    #pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
#endif
typedef long long int ll;
typedef pair<int, int> ii;
const int inf = 10000000;
const double eps = 1e-12;
#define itn int
#define tmep temp
void solve () {
    int n;
    cin >> n;
    ii next[n + 1];
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        next[i].first = u; next[i].second = v;
    }
    int at = 1;
    vector<int> lis;
    lis.push_back(1);
    while (lis.size() < n) {
        int nei1 = next[at].first, nei2 = next[at].second;
        if (next[nei1].first == nei2 or next[nei1].second == nei2) {
            lis.push_back(nei1);
            at = nei1;
            continue;
        }
        if (next[nei2].first == nei1 or next[nei2].second == nei1) {
            lis.push_back(nei2);
            at = nei2;
            continue;
        }
    }
    for (auto &v : lis) {
        cout << v << " ";
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