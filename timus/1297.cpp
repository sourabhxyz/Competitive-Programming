#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll pow1[1000 + 5], pow2[1000 + 5];
const ll p = 31;
ll m1 = 1e9 + 9, m2 = 1e9 + 7;
ll pref[1000 + 5], suff[1000 + 5];

inline void add(int &a, int b) {
    a += b;
    if (a >= m1) a -= m1;
}

inline void sub(ll &a, ll b) {
    a -= b;
    if (a < 0) a += m1;
}

inline int mul(int a, int b) {
    return (int) ((long long) a * b % m1);
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
    return power(a, m1 - 2);
}

void pre() {
    pow1[0] = 1; pow2[0] = inv(pow1[0]);
    for (int i = 1; i <= 1000; i++) {
        pow1[i] = (pow1[i - 1] * p) % m1;
        pow2[i] = inv(pow1[i]);
    }
}
pair<ll, ll> compute_hash(string const& s) {
    long long hash_value = 0, hash_value2 = 0;
    for (int i = 0; i < s.size(); i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * pow1[i]) % m1;
//        hash_value2 = (hash_value2 + (s[i] - 'a' + 1) * pow2[i]) % m2;
        pref[i] = hash_value;
    }
    string nw = s;
    reverse(nw.begin(), nw.end());
    for (int i = 0; i < s.size(); i++) {
        hash_value2 = (hash_value2 + (nw[i] - 'a' + 1) * pow1[i]) % m1;
//        hash_value2 = (hash_value2 + (s[i] - 'a' + 1) * pow2[i]) % m2;
        suff[i] = hash_value2;
    }
    return make_pair(hash_value, hash_value2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    pre();
    string s;
    cin >> s;
    for (int i = 0; i < s.size() + 3; i++) {
        pref[i] = suff[i] = 0;
    }
    compute_hash(s);
    int ans = 1;
    int lans = 0;
    int rans = 0;
    for (int l = 0; l < s.size(); l++) {
        for (int r = l + 1; r < s.size(); r++) {
            ll hsh = pref[r];
            sub(hsh, pref[l - 1]);
            hsh = mul(hsh, pow2[l]);
            int nr = s.size() - l - 1, nl = s.size() - r - 1;
            ll hsh2 = suff[nr];
            sub(hsh2, suff[nl - 1]);
            hsh2 = mul(hsh2, pow2[nl]);
            if (hsh == hsh2) {
                if (r - l + 1 > ans) {
                    ans = r - l + 1;
                    lans = l;
                    rans = r;
                }
            }
        }
    }
    for (int i = lans; i <= rans; i++) {
        cout << s[i];
    }

    return 0;
}