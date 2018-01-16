#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    int a, b;
    while(cin >> n >> a >> b) {
        if (a + b == n) {
            cout << "1\n";
            continue;
        } else {
            int ans = 1;
            for (int x = 1; x < n; x++) {
                int y = n - x;
                ans = max(ans, min(a / x, b / y));
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
