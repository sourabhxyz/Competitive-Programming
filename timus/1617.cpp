#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
#define inf 1e14
#define end en

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(0);
    int n;
    cin >> n;
    int arr[101];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
        int tmep;
        cin >> tmep;
        tmep -= 600;
        arr[tmep]++;
    }
    int ans = 0;
    for (int i = 0; i < 101; i++) {
        if (arr[i] >= 4) {
            ans += (arr[i] / 4);
        }
    }
    cout << ans << "\n";
}