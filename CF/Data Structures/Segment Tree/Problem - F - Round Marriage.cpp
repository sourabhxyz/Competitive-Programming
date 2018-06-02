#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;

constexpr int MAXN = 400005;
int n; ll L;
ll a[MAXN], b[MAXN];
/* Key lemmas */
// 1) the case "r - l + 1 >= L" is equivalent to saying "2x + 1 >= L" thus all the points will have same
// interval and therefore the possibility of this case in presence with other different intervals is
// not possible. Therefore by "Crossing Intervals" I will not mean this case.
// 2) Crossing intervals need not be for duplicate points.
// 3) Creating duplicate points (a) should be easily evident as the first interval could start for some
// other a[i].
// 4) Duplicate interval can cover different points, i.e. duplicate interval need not be for 
// same duplicate points. (see photo).
// 5) 
bool poss(ll x) {
    assert(x > 0);
    // generate intervals [b[i] - x, b[i] + x]
    vector<pii> intervals;
    for (int i = 0; i < n; ++i) {
        ll l = b[i] - x;
        ll r = b[i] + x;
        if (r - l + 1 >= L) { // forget about the possibility of this case in presenc
            intervals.emplace_back(0, L - 1);
            intervals.emplace_back(L, L + L - 1);
            continue;
        }

        if (l < 0)
            l += L;
        if (r >= L)
            r -= L;

        if (l < r) {
            intervals.emplace_back(l, r);
            intervals.emplace_back(l + L, r + L);
        } else {
            intervals.emplace_back(l, r + L);
        }
    }

    sort(begin(intervals), end(intervals));
    int ptr = 0;
    ll l, r;
    for (auto& ival : intervals) {
        tie(l, r) = ival;
        while (ptr < 2 * n and a[ptr] < l) ++ptr;
        if (ptr >= 2 * n or a[ptr] > r) return false;
        ++ptr;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %lld", &n, &L);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &a[i]);
    }
    sort(a, a + n);
    for (int i = n; i < 2 * n; ++i) {
        a[i] = a[i - n] + L;
    }

    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &b[i]);
    }
    sort(b, b + n);
    bool all_eq = true;
    for (int i = 0; i < n; ++i)
        all_eq &= a[i] == b[i];

    if (all_eq)
        return printf("%d\n", 0), 0;

    ll lo = 0;
    ll hi = L + 1;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2LL;
        if (poss(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%lld\n", hi);

    return 0;
}