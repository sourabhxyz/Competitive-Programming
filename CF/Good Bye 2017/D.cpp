#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int md = 1e9 + 7;

inline int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

inline int mul(int a, int b) {
    return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a) {
    return power(a, md - 2);
}

int k, pa, pb;
vector<vector<int> > dp;

int calc(int n, int m) {
    if (m >= k) {
        return m;
    }
    if (n == k) {
        int mean = mul(sub(1, pb), inv(pb));
        return add(m, add(k, mean));
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    return dp[n][m] = add(mul(pa, calc(n + 1, m)), mul(pb, calc(n, n + m)));
}

void solve() {
    cin >> k >> pa >> pb;
    dp.assign(k + 5, vector<int>(k + 5, -1));
    int den = inv(pa + pb);
    pa = mul(pa, den);
    pb = mul(pb, den);
    cout << calc(1, 0) << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    cout << fixed << setprecision(8);
//    freopen("ina.txt", "r", stdin);
//    freopen("outa.txt", "w", stdout);
    solve();
    return 0;
}
