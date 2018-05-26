#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    if (n == 1) {
        cout << 2 * data[0];
    } else {
        sort(data.begin(), data.end());
        int ans = data[0];
        for (int i = 0; i < data.size() - 1; i++) {
            ans += max(data[i + 1], data[i]);
        }
        ans += data[n - 1];
        cout << ans << "\n";
    }

}