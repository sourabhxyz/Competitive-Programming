#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int a, b;
    cin >> a >> b;
    cout << (b - a + 1) - (b / 2 - ((a - 1) / 2));

    return 0;
}