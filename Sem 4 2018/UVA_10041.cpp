#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int ans = INT_MAX;
        int r;
        cin >> r;
        vector<int> arr(r);
        for (int i = 0; i < r; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < r; i++) {
            int temp = 0;
            for (int j = 0; j < r; j++) {
                temp += abs(arr[i] - arr[j]);
            }
            ans = min(ans, temp);
        }
        cout << ans << "\n";
    }

    return 0;
}
