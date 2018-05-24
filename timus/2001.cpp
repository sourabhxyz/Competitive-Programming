#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int a[4], b[4];
    for (int i = 1; i <= 3; i++) {
        cin >> a[i] >> b[i];
    }
    cout << a[1] - a[3] << " " << b[1] - b[2] << "\n";

}