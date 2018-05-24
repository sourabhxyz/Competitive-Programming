#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int dr[] = {2, 2, -2, -2, -1, 1, -1, 1};
int dc[] = {-1, 1, -1, 1, 2, 2, -2, -2};
bool check(int r, int c) {
    if (r < 1 or r > 8 or c < 1 or c > 8) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    vector<int> a[3];
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < a[0].size(); i++) {
        int at = a[0][i];
        if (binary_search(a[1].begin(), a[1].end(), at) and binary_search(a[2].begin(), a[2].end(), at)) {
            ans++;
        }
    }
    cout << ans << "\n";
}

