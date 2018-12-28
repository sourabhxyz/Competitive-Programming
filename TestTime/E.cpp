#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
    #pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
#endif
typedef long long int ll;
typedef pair<int, int> ii;
const int inf = 10000000;
const double eps = 1e-12;
#define itn int
#define tmep temp
int tillDep[1000005];
struct segmentTree {
    struct seg {
        int val;
        seg () { val = 0; }
    };
    vector<seg> st;
    segmentTree () {
    }
    segmentTree (int n) {
        st.resize (4 * n);
    }
    int left(int at) { return at << 1; }
    int right(int at) {return at << 1 | 1; }
    void build (int at, int start, int end) {
        if (start == end) {
            st[at].val = tillDep[start];
        } else {
            int mid = (start + end) >> 1;
            build (left (at), start, mid);
            build (right (at), mid + 1, end);
            st[at].val = min (st[left(at)].val, st[right (at)].val);
        }
    }
    int query(int at, int start, int end, int l, int r) {
        if (start >= l and end <= r) return st[at].val;
        int mid = (start + end) >> 1;
        if (r <= mid) return query (left (at), start, mid, l, r);
        else if (l > mid) return query (right (at), mid + 1, end, l, r);
        auto lf = query(left(at), start, mid, l, r);
        auto ri = query(right(at), mid + 1, end, l, r);
        return min (lf, ri);
    }
};
bool _valid (string &s) {
    itn n = s.size ();
    int dep = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            dep++;
        } else if (s[i] == ')' and dep) {
            dep--;
        } else {
            return false;
        }
    }
    return dep == 0;
}
bool check1 (int n, string &s) {
    segmentTree t (n);
    int dep = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            dep++;
        } else if (s[i] == ')' and dep) {
            dep--;
        } else {
            return false;
        }
        tillDep[i] = dep;
    }
    t.build(1, 0, n - 1);
    if (dep != 2) {
        cout << "0";
        return true;
    }
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (i == n - 1 and tillDep[i] == 2 and s[i] == '(') {
            pos++;
            continue;
        }
        if (s[i] == '(' and tillDep[i] >= 2 and t.query(1, 0, n - 1, i + 1, n - 1) > 1) {
            pos++;
        }
    }
    cout << pos << "\n";
    return true;
}
void solve () {
    int n;
    string s;
    cin >> n >> s;
    if (n & 1) {
        cout << "0";
        return;
    }
    if (check1(n, s)) {}
    else {
        reverse(s.begin (), s.end ());
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') s[i] = '(';
            else s[i] = ')';
        }
        check1 (n, s);
    }
}

int main () {
#ifdef LOCAL
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
#endif
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve ();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}