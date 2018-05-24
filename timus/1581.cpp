#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    int temp;
    cin >> temp;
    int prev = temp;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        if (temp != prev) {
            cout << cnt << " " << prev << " ";
            cnt = 1;
        } else {
            cnt++;
        }
        prev = temp;
    }
    cout << cnt << " " << prev << "\n";
    return 0;
}