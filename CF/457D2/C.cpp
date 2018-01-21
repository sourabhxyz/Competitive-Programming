#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m;
vi primes;
bitset<1000005> bs;
void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (bs[i]) {
            for (int j = i + i; j <= 1000000; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ine.txt", "r", stdin);
    // freopen("oute.txt", "w", stdout);
    cin >> n >> m;
    sieve();
    vector<tuple<int, int, int> > edges;
    int sum = 0;
    for (int i = 0; i < n - 2; i++) {
        edges.push_back({i + 1, i + 2, 2});
        sum += 2;
    }

    auto it = lower_bound(primes.begin(), primes.end(), sum);
    if (*it == sum) {
        it++;
        edges.push_back({n - 1, n, *it - sum});
        sum = *it;
    } else {
        edges.push_back({n - 1, n, *it - sum});
        sum = *it;
    }
    cout << sum << " " << sum << "\n";
    m -= n - 1;
    int lastp = primes[primes.size() - 1];
    for (int i = 1; i <= n and m; i++) {
        for (int j = i + 2; j <= n and m; j++) {
            edges.push_back({i, j, lastp});
            m -= 1;
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        cout << get<0>(edges[i]) << " " << get<1>(edges[i]) << " " << get<2>(edges[i]) << "\n";
    }
    return 0;
}
