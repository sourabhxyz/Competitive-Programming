#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string s = "abcdefghijklmnopqrstuvwxyz .,! ";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int ans = 0;
    char c;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        int mam = i % 3;
        mp[s[i]] = mam + 1;
    }
    while (cin.get(c)) {
        ans += mp[c];
    }
    cout << ans << "\n";
    return 0;
}