#include<bits/stdc++.h>

using namespace std;

#define inf 10000000

void solve() {
    int tc;
    cin >> tc;
    while (tc--) {
        int ctype, s;
        cin >> ctype >> s;
        vector<int> normalval(ctype), ival(ctype);
        vector<vector<int> > dp(s + 1, vector<int> (s + 1, inf));
        dp[0][0] = 0;
        for (int i = 0; i < ctype; i++) {
            cin >> normalval[i] >> ival[i];
        }
        for (int i = 0; i < ctype; i++) {
            for (int j = normalval[i]; j <= s; j++) {
                for (int k = ival[i]; k <= s; k++) {
                    dp[j][k] = min(dp[j][k], dp[j - normalval[i]][k - ival[i]] + 1);
                }
            }
        }
        int ans = inf;
        bool found = false;
        for (int i = 0; i <= s; i++) {
            for (int j = 0; j <= s; j++) {
                if (dp[i][j] != inf and (i * i + j * j) == s * s) {
                    found = true;
                    ans = min(dp[i][j], ans);
                }
            }
        }
        found ? cout << ans << "\n" : cout << "not possible\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    solve();
    return 0;
}
