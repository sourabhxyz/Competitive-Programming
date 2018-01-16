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
    map<int, int> working;
    int n, q;
    cin >> n >> q;
    working[-1] = -1;
    working[1] = n;
    working[2e9] = 2e9;
    int ans = n;
    while (q--) {
        int l, r, work;
        cin >> l >> r >> work;
        work--;
        auto it = working.lower_bound(l);
//        auto it = lower_bound(working.begin(), working.end(), l);
        it--;
        if (it->second >= l) {
            working[l] = it->second;
            it->second = l - 1;
        }
        it++;
        int del = 0;
        while (it->first <= r) {
            if (it->second > r) {
                del += (r - it->first + 1);
                working[r + 1] = it->second;
            } else {
                del += it->second - it->first + 1;
            }
            auto it2 = it;
            it++;
            working.erase(it2);
        }
        ans -= del;
        if (work) {
            ans += r - l + 1;
            working[l] = r;
        }
        cout << ans << "\n";
    }
    return 0;
}
