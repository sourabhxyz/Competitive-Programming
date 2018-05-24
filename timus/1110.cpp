#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int n, m, y;
int po(int num, int pw) {
    int res = 1;
    while (pw) {
        if (pw & 1) res = (res * num) % m;
        num = (num * num) % m;
        pw >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cin >> n >> m >> y;
    bool ok = false;
    for (int i = 0; i < m; i++) {
        if (po(i, n) == y) {
            cout << i << " ";
            ok = true;
        }
    }
    if (!ok) {
        cout << "-1";
    }
}