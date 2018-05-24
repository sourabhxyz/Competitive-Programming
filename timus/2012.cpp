#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int p;
    cin >> p;
    p = 12 - p;
    if (p < 6) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}