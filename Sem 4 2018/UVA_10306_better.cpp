#include <bits/stdc++.h>
using namespace std;
int dp[500][500];
typedef pair<int, int> ii;
const int inf = 1000000;
const double eps = 1e-12;
vector<ii> coins;
int recur (int X, int Y) {
    if (X < 0 or Y < 0) {
        return inf;
    }
    if (dp[X][Y] != -1) {
        return dp[X][Y];
    }
    int ans = inf;
    for (int i = 0; i < coins.size(); i++) {
        ans = min (ans, recur (X - coins[i].first, Y - coins[i].second) + 1);
    }
    return dp[X][Y] = ans;
}
int main ( ) {
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) {
        int m, S;
        cin >> m >> S;
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            coins.push_back(ii(u, v));
        }
        int ans = inf;
        for (int i = 0; i <= S; i++) {
            double j = S * S - i * i;
            j = sqrt (j);
            if (abs (j - round(j)) < eps) {
                ans = min (ans, recur (i, (int)round(j)));
            }
        }
        if (ans != inf) {
            cout << ans << "\n";
        } else {
            cout << "not possible\n";
        }
    }

}
