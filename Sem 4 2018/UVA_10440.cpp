#include<bits/stdc++.h>

using namespace std;

#define inf 10000000

void solve() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, t, m;
        cin >> n >> t >> m;
        vector<int> ferr(m);
        for (int i = 0; i < m; i++) cin >> ferr[i];
        t *= 2;
        int tot = 0;
        for (int i = (m % n == 0 ? n - 1 : m % n - 1); i < m; i += n) {
            tot = t + max(tot, ferr[i]);
        }
        cout << tot - t / 2 << " " << (m + n - 1) / n << "\n";
        /* Not starting first with i = min(n, m) - 1 and then in the end process the i % n will not give
         * the correct answer. To see this, see test case 2 of sample input.
         */
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
