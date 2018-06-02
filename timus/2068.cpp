#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        temp = (temp - 1) / 2;
        if (temp & 1) {
            temp = 1;
        } else temp = 0;
        x ^= temp;
    }
    x ? cout << "Daenerys" : cout << "Stannis";
    return 0;
}
