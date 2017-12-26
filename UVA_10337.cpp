#include<bits/stdc++.h>

using namespace std;

#define inf 1000000
int dist;
int windstrength[10][1005]; //alt, mile
vector<vector<int> > dp;

int recur(int altitude, int mile) {
    if(mile == dist) {
        if(altitude == 0) return 0;
        else return inf;
    }
    if(dp[altitude][mile] != -1) {
        return dp[altitude][mile];
    }
    int op1 = INT_MAX, op2 = INT_MAX;
    if (altitude <= 8) {
        op1 = 60 + recur(altitude + 1, mile + 1);
    }
    if(altitude) {
        op2 = 20 + recur(altitude - 1, mile + 1);
    }
    int op3 = 30 + recur(altitude, mile + 1);
    return dp[altitude][mile] = min(op1, min(op2, op3)) - windstrength[altitude][mile];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> dist;
        dist /= 100;
        for(int i = 9; i >= 0; i--) {
            for(int j = 0; j < dist; j++) {
                cin >> windstrength[i][j];
            }
        }
        dp.assign(10, vector<int>(dist + 5, -1));
        int ans = recur(0, 0);
        cout << ans << "\n\n";
    }
    return 0;
}
