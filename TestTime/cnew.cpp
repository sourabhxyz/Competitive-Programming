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
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
bool bound (int x, int y) {
    return (x >= 0 and y >= 0 and x <= 1000 and y <= 1000);
}
int got[1005][1005];
void solve () {
    vector<ii> data (3);
    for (int i = 0; i < 3; i++) {
        cin >> data[i].first >> data[i].second;
    }
    vector<ii> ans;
    int cnt = 0;
    memset (got, 0, sizeof (got));
//    for (int i = 0; i < 3; i++) {
//        got[data[i].first][data[i].second] = 1;
//        ans.push_back (ii(data[i].first, data[i].second));
//    }
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int x = i, y = j;
            if (got[x][y]) continue;
            int auxcnt = 0;
            for (int l = 0; l < 3; l++) {
                for (int m = l + 1; m < 3; m++) {
                    if (x >= min (data[l].first, data[m].first) and x <= max (data[l].first, data[m].first)) {
                        if (y >= min (data[l].second, data[m].second) and y <= max (data[l].second, data[m].second)) {
                            auxcnt++;
                        } else {
                        }
                    } else {
                    }
                }
            }
            if (auxcnt >= 2) {
                bool canTake = true;
                for (int r = 0; r < 4; r++) {
                    int nx = x + dx[r];
                    int ny = y + dy[y];
                    if (bound(nx, ny)) {
                        bool ok = true;
                        for (int hi = 0; hi < 3; hi++) {
                            if (nx == data[hi].first and ny == data[hi].second) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok and got[nx][ny]) {
                            canTake = false;
                        }
                    }
                }
                if (canTake) {
                    cnt++;
                    ans.push_back(ii(x, y));
                    got[x][y] = 1;
                }
            }
        }
    }
    cout << cnt << "\n";
    for (auto &v : ans) {
        cout << v.first << " " << v.second << "\n";
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