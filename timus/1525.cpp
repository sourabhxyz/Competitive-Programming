#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    ll d[3] = {0, 0, 0};
    ll mx[3] = {0, 0, 0};
    ll mn[3] = {0, 0, 0};
    map<char, int> mp;
    mp['l'] = 0;
    mp['r'] = 0;
    mp['u'] = 1;
    mp['d'] = 1;
    mp['b'] = 2;
    mp['f'] = 2;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'l' or s[i] == 'd' or s[i] == 'b') {
            d[mp[s[i]]]++;
            mx[mp[s[i]]] = max(d[mp[s[i]]], mx[mp[s[i]]]);
        } else {
            d[mp[s[i]]]--;
            mn[mp[s[i]]] = min(d[mp[s[i]]], mn[mp[s[i]]]);
        }
    }
    mx[0] = max(1LL, n - mx[0]);
    mx[1] = max(1LL, m - mx[1]);
    mx[2] = max(1LL, k - mx[2]);
    mn[0] = min(n, 1LL - mn[0]);
    mn[1] = min(m, 1LL - mn[1]);
    mn[2] = min(k, 1LL - mn[2]);
    ll ans = 1;
    for (int i = 0; i < 3; i++) {
        if (mx[i] >= mn[i]) {
            ans *= (mx[i] - mn[i] + 1);
        }
    }
    cout << ans << "\n";
}