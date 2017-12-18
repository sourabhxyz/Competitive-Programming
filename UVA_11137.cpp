#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vector<ll> > memo;
vector<int> coinValue;

ll ways(int type, int value) {
    if (value == 0)              return 1;
    if (value < 0 || type == 21)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(0);
    for(int i = 1; i <= 21; i++) {
        coinValue.push_back(i * i * i);
    }
    int val;
    while(cin >> val) {
        memo.assign(21, vector<ll>(val + 1, -1));
        cout << ways(0, val) << "\n";
    }
    return 0;
}
