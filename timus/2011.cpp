#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
typedef pair<int, int> ii;
#define inf 1e8
#define itn int
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  freopen("inc.txt", "r", stdin);
    //  freopen("outc.txt", "w", stdout);
    // cout << fixed << setprecision(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    do {
        cnt++;
    } while (next_permutation(a.begin(), a.end()) and cnt < 6);
    if (cnt >= 6) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
