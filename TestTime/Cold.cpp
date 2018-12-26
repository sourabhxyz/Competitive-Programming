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
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
bool bound (int x, int y) {
    return (x >= 0 and y >= 0 and x <= 1000 and y <= 1000);
}
int vis[1005][1005];
ii par[1005][1005];
int ans;
int ax, ay, bx, by, cx, cy;
int bkx, bky;
int back1x, back1y, back2x, back2y, s2x, s2y;
bool flag;
int bfs (int x, int y) {
    queue<ii> q;
    vis[x][y] = 0;
    q.push (ii (x, y));
    while (!q.empty()) {
        int ax = q.front().first, ay = q.front().second;
        q.pop ();
        for (int i = 0; i < 4; i++) {
            int nx = ax + dx[i];
            int ny = ay + dy[i];
            if (bound (nx, ny)) {
                if (vis[nx][ny] == -1) {
                    vis[nx][ny] = vis[ax][ay] + 1;
                    par[nx][ny].first = ax; par[nx][ny].second = ay;;
                    q.push(ii(nx, ny));
                    if (flag) {
                        if (nx == bx and ny == by) {
                            if (ans == 0) {
                                back1x = nx;
                                back1y = ny;
                                s2x = nx;
                                s2y = ny;
                            } else {
                                back2x = nx;
                                back2y = ny;
                            }
                            if (ans < vis[nx][ny]) {
                                ans = vis[nx][ny];
                                bkx = nx;
                                bky = ny;
                            }
                        }
                        if (nx == cx and ny == cy) {
                            if (ans == 0) {
                                back1x = nx;
                                back1y = ny;
                                s2x = nx;
                                s2y = ny;
                            } else {
                                back2x = nx;
                                back2y = ny;
                            }
                            if (ans < vis[nx][ny]) {
                                ans = vis[nx][ny];
                                bkx = nx;
                                bky = ny;
                            }
                        }
                    }
                }
            }
        }
    }
}
void solve () {
    memset (vis, -1, sizeof (vis));
    ans = 0;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    bkx = ax; bky = ay;
    s2x = back1x = back2x = ax;
    s2y = back1y = back2y = ay;
    flag = true;
    bfs (ax, ay);
    flag = false;
    cout << ans + 1 << "\n";
    int sx = back1x, sy = back1y;
    cout << ax << " " << ay << "\n";
    while (sx != ax or sy != ay) {
        cout << sx << " " << sy << "\n";
        int ox = par[sx][sy].first, oy = par[sx][sy].second;
        sx = ox; sy = oy;
    }
    memset (vis, -1, sizeof (vis));
    bfs(s2x, s2y);
    sx = back2x; sy = back2y;
    while (sx != s2x or sy != s2y) {
        cout << sx << " " << sy << "\n";
        int ox = par[sx][sy].first, oy = par[sx][sy].second;
        sx = ox; sy = oy;
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