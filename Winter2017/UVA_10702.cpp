#include<bits/stdc++.h>

using namespace std;

int c, s, e, t;
int profit[105][105];
int dp[105][1005]; //dp[i][k] profit to get to city i after k inter-city travels

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 //   freopen("inb.txt", "r", stdin);
 //   freopen("outb.txt", "w", stdout);
    while(cin >> c >> s >> e >> t and (c + s + e + t)) {
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                cin >> profit[i][j];
            }
        }
        for (int i = 0; i < c; i++) for (int k = 0; k <= t; k++) dp[i][k] = 0;
        for (int i = 0; i < c; i++) {
            dp[i][1] = profit[s - 1][i];
        }
        for (int k = 2; k <= t; k++) {
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < c; j++) {
                    int nint = dp[j][k - 1] + profit[j][i];
                    dp[i][k] = max(dp[i][k], nint);
                }
            }
        }
        int mx = INT_MIN;
        for (int i = 0; i < e; i++) {
            int ee;
            cin >> ee;
            if (dp[ee - 1][t] > mx) {
                mx = dp[ee - 1][t];
            }
        }
        cout << mx << "\n";
    }
}
