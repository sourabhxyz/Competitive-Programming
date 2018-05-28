#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
typedef pair<int, int> ii;
#define inf 1e8
#define itn int
#define tmep temp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  freopen("inc.txt", "r", stdin);
    //  freopen("outc.txt", "w", stdout);
    // cout << fixed << setprecision(0);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int tmep;
        cin >> tmep;
        mp[temp]++;
    }
    int mx = 0;
    int ans = -1;
    for (auto &t : mp) {
        if (t.second > mx) {
            mx = t.second;
            ans = t.first;
        }
    }
    cout << ans << "\n";
}
