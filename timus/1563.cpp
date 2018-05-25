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
    int cnt = 0;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string ln;
        getline(cin, ln);
        if (!mp.count(ln)) mp[ln] = 1;
        else cnt++;
    }
    cout << cnt << "\n";
}