#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
    #pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
    #pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
#endif

typedef long long int ll;
typedef pair<int, int> ii;
const int inf = 200 * 200;
const double eps = 1e-12;
#define tmep temp
#define itn int
const int maxn = 100005;
ll pow1[maxn];
const int p = 29;
int m1 = 1e9 + 9, m2 = 1e9 + 7;
string s;
void pre() {
    pow1[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pow1[i] = (pow1[i - 1] * p) % m1;
    }
}
template <typename T>
inline T add(T a, T b) {
    a += b;
    if (a >= m1) a -= m1;
    return a;
}
template <typename T>
inline T sub(T a, T b) {
    a -= b;
    if (a < 0) a += m1;
    return a;
}
template <typename T>
inline T mul(T a, T b) {
    return (T) (((long long) a * b) % m1);
}
template <typename T>
inline T power(T a, T b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul<T>(res, a);
        }
        a = mul<T>(a, a);
        b >>= 1;
    }
    return res;
}
template <typename T>
inline T inv(T a) {
    return power<T>(a, m1 - 2);
}
/* Basic Segment Tree */
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
            st[at].val = s[start] - 'a' + 1;
        } else {
            int mid = (start + end) >> 1;
            build (left (at), start, mid);
            build (right (at), mid + 1, end);
            st[at].val = add<int> (st[left(at)].val, mul<int> (st[right (at)].val, pow1[mid - start + 1]));
        }
    }
    void update(int at, int start, int end, int l, int r, char c) {
        if(r < start || end < l || start > end) return;
        if(start == end) {
            st[at].val = c - 'a' + 1;
            return;
        }
        int mid = (start + end) >> 1;
        update(left(at), start, mid, l, r, c);
        update(right(at), mid + 1, end, l, r, c);
        st[at].val = add<int> (st[left(at)].val, mul<int> (st[right (at)].val, pow1[mid - start + 1]));
    }
    pair<int, ii> query(int at, int start, int end, int l, int r) {
        if (start >= l and end <= r) return make_pair (st[at].val, ii (start, end));
        int mid = (start + end) >> 1;
        if (r <= mid) return query (left (at), start, mid, l, r);
        else if (l > mid) return query (right (at), mid + 1, end, l, r);
        auto lf = query(left(at), start, mid, l, r);
        auto ri = query(right(at), mid + 1, end, l, r);
        int ret = add<int> (lf.first, mul<int> (ri.first, pow1[lf.second.second - lf.second.first + 1]));
        return make_pair(ret, ii(lf.second.first, ri.second.second));
    }
};
bool treesSame (segmentTree &t1, segmentTree &t2, int n) {
    for (int i = 0; i < 4 * n; i++) {
        if (t1.st[i].val != t2.st[i].val) {
            return false;
        }
    }
    return true;
}
void solve () {
    pre ();
    cin >> s;
    int n = s.size();
    segmentTree T1 (n);
    T1.build(1, 0, n - 1);
    reverse(s.begin(), s.end());
    segmentTree T2 (n);
    T2.build(1, 0, n - 1);
//    assert (treesSame(T1, T2, n));
    int m;
    cin >> m;
    string cs;
    for (int i = 0; i < m; i++) {
         cin >> cs;
         if (cs[0] == 'p') {
             int l, r;
             cin >> l >> r;
             l--; r--;
             int nl = n - r - 1;
             int nr = n - l - 1;
             int a = T1.query(1, 0, n - 1, l, r).first;
             int b = T2.query(1, 0, n - 1, nl, nr).first;
             if (a == b) {
                 cout << "Yes\n";
             } else {
                 cout << "No\n";
             }
         } else {
             int pos;
             char c;
             cin >> pos >> c;
             pos--;
             int npos = n - 1 - pos;
             T1.update(1, 0, n - 1, pos, pos, c);
             T2.update(1, 0, n - 1, npos, npos, c);
         }
    }
}
int main ( ) {
#ifdef LOCAL
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve ();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}