#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        temp--;
        a[temp]++;
    }
    for (int i = 0; i < n; i++) {
        cout << (double)a[i] * 100 / m << "%\n";
    }
    return 0;
}