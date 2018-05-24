#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("inc.txt", "r", stdin);
   // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<int> arr(n);
    int ans = 0;
    int ind = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int sum = 0;
        if (i > 1) {
           sum = arr[i] + arr[i - 1] + arr[i - 2];
           if (sum > ans) {
               ans = sum;
               ind = i - 1;
           }
        }
    }
    cout << ans << " " << ind + 1 << "\n";
}


