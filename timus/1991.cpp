#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int n, k;
    cin >> n >> k;
    int boom = 0, droid = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        droid += max(0, k - temp);
        boom += max(0, temp - k);
    }
    cout << boom << " " << droid << "\n";
    return 0;
}