#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    long double inp;
    vector<double> ans;
    while (cin >> inp) {
        ans.push_back(sqrt(inp));
    }
    reverse(ans.begin(), ans.end());
    for (auto &d : ans) {
        cout << d << "\n";
    }
}