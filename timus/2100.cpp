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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt++;
        bool ok = false;
        if (s.size() >= 4) {
            if (s[s.size() - 4] == '+') ok = true;
        }
        if (ok) cnt++;
    }
    cnt += 2;
    if (cnt == 13) cnt++;
    cout << cnt << "00\n";
}



