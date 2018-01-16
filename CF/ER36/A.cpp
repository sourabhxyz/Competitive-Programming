#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ina.txt", "r", stdin);
    // freopen("outa.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (k % a[i] == 0) {
            ans = min(ans, k / a[i]);
        }
    }
    cout << ans << "\n";

}
