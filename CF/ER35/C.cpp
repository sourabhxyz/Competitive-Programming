#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("inc.txt", "r", stdin);
    //freopen("outc.txt", "w", stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    vector<int> k(3);
    while(cin >> k[0] >> k[1] >> k[2]) {
        sort(k.begin(), k.end());
        if (k[0] > 3) {
            cout << "NO\n";
            continue;
        }
        if (k[0] == 3 and k[2] == 3) {
            cout << "YES\n";
            continue;
        }
        if (k[0] == 1) {
            cout << "YES\n";
            continue;
        }
        if (k[0] == 2 and k[1] == 2) {
            cout << "YES\n";
            continue;
        }
        if (k[0] == 2 and k[1] == 4 and k[2] == 4) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
