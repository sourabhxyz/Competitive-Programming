#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    string s;
    cin >> s;
    map<string, int> mp;
    for (int i = 0; i < s.size(); i++) {
        string sub;
        for (int j = i; j < s.size(); j++) {
            sub.push_back(s[j]);
            mp[sub]++;
        }
    }
    int mx = -1;
    string ans;
    for (auto &t : mp) {
        if (mx < t.second) {
            mx = t.second;
            ans = t.first;
        }
    }
    cout << ans << "\n";
}