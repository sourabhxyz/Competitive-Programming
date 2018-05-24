#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int a, b, c;
    cin >> a >> b >> c;
    int one = a - b * c;
    int two = a - b - c;
    cout << min(one, two) << "\n";
}

