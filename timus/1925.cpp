#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int ex = 0, ac = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ex += (a - 2);
        ac += b;
    }
    ex += k - 2;
    if (ex - ac > 0) {
        cout << ex - ac << "\n";
    } else {
        cout << "Big Bang!\n";
    }
}