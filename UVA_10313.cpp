#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<int> coinValue;
/*ll ways(int type, int value, int limit) {
    if (value == 0)              return 1;
    if (value < 0 || type == limit)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value, limit) + ways(type, value - coinValue[type], limit);
}*/

long double dp[300][305] = {};

void pre() {
    for(int i = 1; i <= 300; i++) {
        coinValue.push_back(i);
    }
    dp[0][0] = 1; //rest all are 0;
    for(int i = 0; i < 300; i++){
        if(i) {
            for(int j = 0; j <= 300; j++) {
                dp[i][j] = dp[i - 1][j];
            }
        }
        for(int j = coinValue[i]; j <= 300; ++j)
            dp[i][j] += dp[i][j - coinValue[i]];
    }
    //cout << dp[299][6] << " " << dp[2][6] << " " << dp[4][6] - dp[0][6] << " " << dp[5][6] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(0);
    pre();
    string line;
    while(getline(cin, line)) {
        stringstream ss;
        ss << line;
        int val, left = -1, right = -1;
        ss >> val >> left >> right;
        if(left == -1) {
            cout << dp[299][val] << "\n";
            continue;
        }
        if(right == -1) {
            if(val == 0 and left >= val) {
                cout << "1\n";
                continue;
            }
            if(left > 300) left = 300;
            cout << dp[left - 1][val] << "\n";
            continue;
        }
        else {
            if(val == 0 and left == val) {
                cout << "1\n";
                continue;
            }
            else if(val == 0 and left > val) {
                cout << "0\n";
                continue;
            }
            if(right > 300) right = 300;
            if(left > 300) left = 300;
            long double ans = dp[right - 1][val];;
            if(left > 1) ans -= dp[left - 2][val];
            cout << ans << "\n";
        }
    }
    return 0;
}
