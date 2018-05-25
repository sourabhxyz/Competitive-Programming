#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for (auto &t : mp) {
        if (t.second >= 2) {
            cout << t.first << "\n";
        }
    }
}