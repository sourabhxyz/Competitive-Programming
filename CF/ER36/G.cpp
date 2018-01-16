#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define inf 100000000
int md = 1000000007;
const int  limit = 2000005;
bitset<limit> bs;
int mu[limit];

void sieve(int up) {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= up; i++) {
        if (bs[i]) {
            ll temp = (ll)i * i;
            for (int j = i; j <= up; j += i) {
                if (temp <= up and j % temp == 0) {
                    mu[j] = -inf;
                } else mu[j] += 1;
                if (j != i) bs[j] = 0;
            }
        }
    }
}

void compmu(int up) {
    mu[0] = 0;
    mu[1] = 1;
    for (int i = 2; i <= up; i++) {
        if (mu[i] < 0) {
            mu[i] = 0;
        }
        else if (mu[i] & 1) {
            mu[i] = -1;
        } else {
            mu[i] = 1;
        }
    }
}

vector<int> pw;

int getfj(int j, int i) {
    int check = i / j;
    return pw[check];
}

int getpow(int base, int p) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = ((ll)ans * base) % md;
        }
        base = ((ll)base * base) % md;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  freopen("ine.txt", "r", stdin);
    //  freopen("oute.txt", "w", stdout);
    memset(mu, 0, sizeof(mu));
    int n, k;
    cin >> n >> k;
    sieve(k);
    compmu(k);
    pw.assign(k + 5, 0);
    for (int i = 1; i <= k; i++) {
        pw[i] = getpow(i, n);
    }
    vector<int> b(k + 5, 0);
    for (int j = 1; j <= k; j++) {
        for (int i = j; i <= k; i += j) {
            b[i] += mu[j] * (getfj(j, i) - getfj(j, i - 1));
            b[i] %= md;
            if (b[i] < 0) b[i] += md;
        }
    }
    for (int i = 1; i < k; i++) {
        b[i + 1] += b[i];
        b[i + 1] %= md;
    }
    int finalans = 0;
    for (int i = 1; i <= k; i++) {
        b[i] = b[i] ^ i;
        b[i] %= md;
        if (b[i] < 0) b[i] %= md;
        finalans += b[i];
        finalans %= md;
    }
    cout << finalans << "\n";
}
