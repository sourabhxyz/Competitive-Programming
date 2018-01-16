#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    int ans = 0;
    if (r - l + 1 == n) {
        cout << "0\n";
        return 0;
    }
    if (pos >= l and pos <= r) {
        if (r == n) {
            ans = pos - l + 1;
            cout << ans << "\n";
            return 0;
        } else if (l == 1) {
            ans = r - pos + 1;
            cout << ans << "\n";
            return 0;
        } else {
            if (r - pos <= pos - l) {
                ans = (r - pos + 1) + (r - l + 1);
                cout << ans << "\n";
                return 0;
            } else {
                ans = (pos - l + 1) + (r - l + 1);
                cout << ans << "\n";
                return 0;
            }
        }
    }
    if (pos < l) {
        if (r != n) {
            ans = l - pos + 1 + (r - l) + 1;
            cout << ans << "\n";
            return 0;
        } else {
            ans = l - pos + 1;
            cout << ans << "\n";
            return 0;
        }
    } else {
        if (l != 1) {
            ans = pos - r + 1 + (r - l + 1);
            cout << ans << "\n";
            return 0;
        } else {
            ans = pos - r + 1;
            cout << ans << "\n";
            return 0;
        }
    }
}
