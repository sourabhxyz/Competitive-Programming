#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ine.txt", "r", stdin);
    // freopen("oute.txt", "w", stdout);
    ll n;
    int k;
    cin >> n >> k;
    map<int, int> bcnt;
    int tot = 0;
    for (int i = 0; i <= 63; i++) {
        if (((n >> i) & 1)) {
            bcnt[i]++;
            tot++;
        }
    }
    if (tot > k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 63; i >= -63; i--) {
        if (tot + bcnt[i] <= k) {
            bcnt[i - 1] += 2 * bcnt[i];
            tot += bcnt[i];
            bcnt[i] = 0;
        } else break;
    }
    multiset<int> final;
    for (int i = 63; i >= -63; i--) {
        for (int j = 0; j < bcnt[i]; j++) {
            final.insert(i);
        }
    }
    while (tot < k) {
        auto it = final.begin();
        final.insert(*it - 1);
        final.insert(*it - 1);
        final.erase(it);
        tot++;
    }
    for (auto it = final.rbegin(); it != final.rend(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}
