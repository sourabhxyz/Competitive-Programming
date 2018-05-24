#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inc.txt", "r", stdin);
    //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    n = (n * (n + 1) / 2);
    if (n & 1) {
        cout << "grimy";
    } else {
        cout << "black";
    }
}


