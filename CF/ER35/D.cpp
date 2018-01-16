#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inc.txt", "r", stdin);
    //freopen("outc.txt", "w", stdout);
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int swaps = 0;
        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                if (arr[i] < arr[j]) swaps++;
            }
        }
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;
            swaps += (r - l + 1) / 2;
            if (swaps & 1) {
                cout << "odd\n";
            } else {
                cout << "even\n";
            }
        }

    }
    return 0;
}
