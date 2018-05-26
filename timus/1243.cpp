#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-9;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = (ans * 10) % 7;
        ans = (ans + (s[i] - '0')) % 7;
    }
    cout << ans << "\n";
}