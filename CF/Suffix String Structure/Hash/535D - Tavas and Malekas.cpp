#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll pow1[1000000 + 5], pow2[1000000 + 5], pow3[1000000 + 5], pow4[1000000 + 5];
const ll p = 31;
ll m1 = 1e9 + 9, m2 = 1e9 + 7;
ll pref1[1000000 + 5], pref2[1000000 + 5];

ll add(int a, int b, ll m) {
    a += b;
    if (a >= m) a -= m;
    return a;
}

ll sub(ll a, ll b, ll m) {
    a -= b;
    if (a < 0) a += m;
    return a;
}

inline int mul(int a, int b, ll m) {
    return (int) ((long long) a * b % m);
}

inline int power(int a, long long b, ll m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a, m);
        }
        a = mul(a, a, m);
        b >>= 1;
    }
    return res;
}

inline int inv(int a, int m) {
    return power(a, m - 2, m);
}

void pre() {
    pow1[0] = 1; pow2[0] = inv(pow1[0], m1), pow3[0] = 1, pow4[0] = inv(pow3[0], m2);
    for (int i = 1; i <= 1000000; i++) {
        pow1[i] = (pow1[i - 1] * p) % m1;
        pow3[i] = (pow3[i - 1] * p) % m2;
        pow2[i] = inv(pow1[i], m1);
        pow4[i] = inv(pow3[i], m2);
    }
}
pair<ll, ll> compute_hash(string const& s) {
    long long hash_value = 0, hash_value2 = 0;
    for (int i = 0; i < s.size(); i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * pow1[i]) % m1;
        hash_value2 = (hash_value2 + (s[i] - 'a' + 1) * pow3[i]) % m2;
        pref1[i] = hash_value;
        pref2[i] = hash_value2;
    }
    return make_pair(hash_value, hash_value2);
}

int n, m;
string pm;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  freopen("ina.txt", "r", stdin);
    //  freopen("outa.txt", "w", stdout);
    cin >> n >> m;
    cin >> pm;
    if (m == 0) {
        cout << power(26, n, m2) << "\n";
        return 0;
    }
    pre();
    compute_hash(pm);
    int prev = 0;
    int u;
    cin >> u;
    u--;
    int qcnt = u;
    bool ok = true;
    prev = u + pm.size() - 1;
    int oldstart = u;
    ll hsh1, hsh2, hsh3, hsh4;
    for (int i = 0; i < m - 1; i++) {
        cin >> u;
        u--;
        if (u + pm.size() > n) {
            ok = false;
            break;
        }
        if (u > prev) {
            qcnt += u - prev - 1;
            prev = u + pm.size() - 1;
            oldstart = u;
        } else {
            hsh1 = sub(pref1[prev - oldstart], pref1[u - oldstart - 1], m1);
            hsh1 = mul(hsh1, pow2[u - oldstart], m1);
            hsh2 = sub(pref2[prev - oldstart], pref2[u - oldstart - 1], m2);
            hsh2 = mul(hsh2, pow4[u - oldstart], m2);
            hsh3 = pref1[prev - u], hsh4 = pref2[prev - u];
            if (hsh1 == hsh3 and hsh2 == hsh4) {
                oldstart = u;
                prev = u + pm.size() - 1;
            } else {
                ok = false;
                break;
            }
        }
    }
    if (!ok) {
        cout << "0\n";
        return 0;
    } else {
        qcnt += n - 1 - prev;
        int ans = power(26, qcnt, m2);
        cout << ans << "\n";
    }
}