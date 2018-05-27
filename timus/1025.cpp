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
     freopen("inc.txt", "r", stdin);
     freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(0);
    int k;
    cin >> k;
    int need = (k / 2) + 1;
    int data[k];
    for (int i = 0; i < k; i++) cin >> data[i];
    int ans = 0;
    sort(data, data + k);
    for (int i = 0; i < need; i++) {
        ans += (data[i] / 2) + 1;
    }
    cout << ans << "\n";
}