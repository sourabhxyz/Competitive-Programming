#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    int n;
    ll m;
    cin >> n >> m;
    int gcdd;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    gcdd = n == 1 ? arr[0] - 1 : gcd(arr[0] - 1, arr[1] - 1);
    for (int i = 2; i < n; i++) {
        gcdd = gcd(gcdd, arr[i] - 1);
    }
    while (gcdd % 2 == 0) gcdd /= 2;
    vector<int> divs;
    for (int i = 1; i * i <= gcdd; i++) {
        if (gcdd % i == 0) {
            divs.push_back(i);
            if (gcdd / i != i) {
                divs.push_back(gcdd / i);
            }
        }
    }
    ll ans = 0;
    for (auto d : divs) {
        ll tld = d;
        while (tld <= m - 1) {
            ans += (m - tld);
            tld *= 2;
        }
    }
    cout << ans << "\n";
    return 0;
}
