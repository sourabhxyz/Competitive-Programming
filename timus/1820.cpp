#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int n, k;
    cin >> n >> k;
    if (n <= k) {
        cout << "2\n";
    } else if (k == 1) {
        cout << 2 * n << "\n";
    } else if (n % k == 0) {
        cout << (n / k * 2) << "\n";
    } else {
        int temp = n / k;
        temp++;
        n -= (k - n % k);
        temp += ((n + k - 1) / k);
        cout << temp << "\n";
    }
}

