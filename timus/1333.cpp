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
struct circle {
    double x, y, r;
    circle () {}
};
bool inside (circle &c, double x, double y) {
    return (c.r + eps > hypot (abs(c.x - x), abs(c.y - y)));
}
void solve () {
    cout << fixed << setprecision (3);
    int n;
    cin >> n;
    vector<circle> data (n);
    for (int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        data[i].x = x, data[i].y = y, data[i].r = r;
    }
    double lim = 1.0/200;
    double ans = 0;
    double siz = lim * lim;
    for (int i = 1; i < 200; i++) {
        for (int j = 1; j < 200; j++) {
            double x = lim * i, y = lim * j;
            for (int c = 0; c < n; c++) {
                if (inside (data[c], x, y)) {
                    ans += siz;
                    break;
                }
            }
        }
    }
    cout << ans * 100 << "\n";
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