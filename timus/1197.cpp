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
  //  freopen("inc.txt", "r", stdin);
  //  freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char rr;
        cin >> rr;
        int r = rr - 'a' + 1;
        int c;
        cin >> c;
        int ans = 0;
        for (int j = 0; j < 8; j++) {
            if (check(r + dr[j], c + dc[j])) ans++;
        }
        cout << ans << "\n";
    }
}
