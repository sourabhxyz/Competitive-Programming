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
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << s;
        return;
    }
    string as;
    int n = s.size();
    if ((n & 1) == 0) {
        int i = n - 1;
        int k = 0;
        while (i >= k) {
            as.push_back(s[i--]);
            as.push_back(s[k++]);
        }
        reverse(as.begin (), as.end ());
        cout << as;
        return;
    } else {
        int i = n - 1;
        int k = 0;
        while (i >= k) {
            as.push_back(s[k++]);
            as.push_back(s[i--]);
        }
        as.pop_back ();
        reverse(as.begin (), as.end ());
        cout << as;
        return;
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