#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int n;
ll dp[46][3];
map<char, int> mp;
ll recur(int at, char prev) {
    if (at > n) return 0;
    if (at == n) return 1;
    if (dp[at][mp[prev]] != -1) {
        return dp[at][mp[prev]];
    }
    ll &ret = dp[at][mp[prev]];
    ret = 0;
    if (prev == 'R') {
        ret += recur(at + 2, 'W');
        ret += recur(at + 1, 'W');
    }
    if (prev == 'W') {
        ret += recur(at + 2, 'R');
        ret += recur(at + 1, 'R');
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("inc.txt", "r", stdin);
   // freopen("outc.txt", "w", stdout);
    cin >> n;
    mp['R'] = 0;
    mp['B'] = 1;
    mp['W'] = 2;
    for (int i = 0; i < 46; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }
    cout << recur(1, 'R') + recur(1, 'W');
}



