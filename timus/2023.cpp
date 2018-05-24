#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inc.txt", "r", stdin);
    //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    map<char, int> mp;
    mp['A'] = 1;
    mp['B'] = 2;
    mp['D'] = 3;
    mp['J'] = 3;
    mp['G'] = 3;
    mp['P'] = 1;
    mp['O'] = 1;
    mp['M'] = 2;
    mp['K'] = 3;
    mp['R'] = 1;
    mp['S'] = 2;
    mp['T'] = 3;
    mp['W'] = 3;
    int at = 1;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int to = mp[s[0]];
        ans += abs(to - at);
        at = to;
    }
    cout << ans << "\n";
}



