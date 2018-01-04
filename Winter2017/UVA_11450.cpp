#include<bits/stdc++.h>

using namespace std;

int m, c;
vector<vector<int> > garmentmodel;
vector<vector<int> > dp;

int recur(int moneyleft, int garmentno) {
    if(moneyleft == 0) return 0;
    if(garmentno == c) return moneyleft;
    if(dp[moneyleft][garmentno] != -1) {
        return dp[moneyleft][garmentno];
    }
    int op1 = recur(moneyleft, garmentno + 1);
    int op2 = INT_MAX;
    for(int i = 0; i < garmentmodel[garmentno].size(); i++) {
        if(moneyleft < garmentmodel[garmentno][i]) continue;
        op2 = min(op2, recur(moneyleft - garmentmodel[garmentno][i], garmentno + 1));
    }
    return dp[moneyleft][garmentno] = min(op1, op2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> m >> c;
        garmentmodel.clear();
        garmentmodel.resize(c);
        int check = 0;
        for(int i = 0; i < c; i++) {
            int k;
            cin >> k;
            garmentmodel[i].resize(k);
            int mn = INT_MAX;
            for(int j = 0; j < k; j++) {
                cin >> garmentmodel[i][j];
                mn = min(mn, garmentmodel[i][j]);
            }
            check += mn;
        }
        dp.assign(m + 5, vector<int>(c + 5, -1));
        int ans = recur(m, 0);
        m - ans >= check ? cout << m - ans << "\n" : cout << "no solution\n";
    }

}
