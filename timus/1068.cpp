#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inc.txt", "r", stdin);
    //freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    if (n >= 1) {
        cout << (n * (n + 1) / 2);
    } else if (n == 0 ){
        cout << "1";
    } else {
        n = abs(n);
        cout << -(n * (n + 1) / 2 - 1);
    }
}



