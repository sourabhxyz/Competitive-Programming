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
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        sum += data[i];
        if (sum < 0) sum = 0;
        ans = max(ans, sum);
    }
    cout << ans << "\n";

}