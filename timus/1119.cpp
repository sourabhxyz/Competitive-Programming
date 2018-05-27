#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
#define inf 1e14
#define end en
bool ctake[1005][1005];
double dp[1005][1005];
int n, m;
const double o2 = 100 * sqrt(2);
bool bound(int i, int j) {
    if (i == n + 1 or j == m + 1) return false;
    return true;
}
double recur(int i, int j) {
    if (i == n and j == m) {
        return 0;
    }
    if (!bound(i, j)) return inf;
    if (dp[i][j] > -eps) return dp[i][j];
    double &ret = dp[i][j];
    ret = 0;
    double op1 = inf, op2 = inf, op3 = inf;
    op1 = 100 + recur(i, j + 1);
    op2 = 100 + recur(i + 1, j);
    if (ctake[i][j]) {
        op3 = o2 + recur(i + 1, j + 1);
    }
    return ret = min(op1, min(op2, op3));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(0);
    cin >> n >> m;
    int k;
    for (int i = 0; i <= max(n, m); i++) {
        for (int j = 0; j <= max(n, m); j++) {
            dp[i][j] = -1;
            ctake[i][j] = false;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ctake[a][b] = true;
    }

    cout << recur(0, 0);
}