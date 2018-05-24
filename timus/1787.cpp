#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int k, n;
    cin >> k >> n;
    int temp = k;
    for (int i = 0; i < n; i++) {
        int temp2;
        cin >> temp2;
        temp -= k;
        temp = max(0, temp);
        temp = temp + temp2;
    }
    cout << max(0, temp - k) << "\n";
}