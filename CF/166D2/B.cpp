#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int n, m;
int mat[505][505];
bitset<1000000> bs;
vector<int> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= 100005; i++) {
        if (bs[i]) {
            for (ll j = (ll)i * i; j <= 100005; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}


ll applyrow(int index) {
    ll diff = 0;
    for (int j = 0; j < m; j++) {
        auto it = lower_bound(primes.begin(), primes.end(), mat[index][j]);
        diff += (*it - mat[index][j]);
    }
    return diff;
}

ll applycol(int index) {
    ll diff = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(primes.begin(), primes.end(), mat[i][index]);
        diff += (*it - mat[i][index]);
    }
    return diff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    sieve();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, applyrow(i));
    }
    for (int j = 0; j < m; j++) {
        ans = min(ans, applycol(j));
    }
    cout << ans << "\n";
    return 0;
}
