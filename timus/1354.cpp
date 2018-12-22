#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
    #pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
    #pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
#endif
typedef long long int ll;
typedef pair<int, int> ii;
const int inf = 1000000;
const double eps = 1e-12;
struct estatse {
    int occ, len, quicklink, link;
    map<int, int> next;
    estatse () { occ = 0; }
};
struct eertree {
    int palsuf, siz;
    vector<estatse> tree;
    // 0 is imaginary node, 1 is epsilon node
    eertree () {
        siz = 2;
        tree.resize (2);
        tree[0].len = -1;
        tree[0].link = 0;
        tree[0].quicklink = 0;
        tree[0].occ = 0;
        tree[1].len = 0;
        tree[1].link = 0;
        tree[1].quicklink = 0;
        tree[1].occ = 0;
        palsuf = 1;
    }
    int add (int i, string &s) {
        int cur = palsuf;
        while (true) {
            int curlen = tree[cur].len;
            int linklen = tree[tree[cur].link].len;
            if (i - 1 - curlen >= 0 and s[i - 1 - curlen] == s[i]) break;
            if (i - 1 - curlen >= 0 and s[i - 1 - curlen] != s[i] and s[i - 1 - linklen] != s[i]) {
                cur = tree[cur].quicklink;
            } else {
                cur = tree[cur].link;
            }
        }
        if (tree[cur].next.count (s[i])) {
            palsuf = tree[cur].next[s[i]];
            return 0;
        }
        siz++;
        palsuf = siz - 1;
        estatse nw;
        tree[cur].next[s[i]] = siz - 1;
        nw.len = tree[cur].len + 2;
        if (nw.len == 1) {
            nw.link = 1;
        } else {
            cur = tree[cur].link;
            while (true) {
                int curlen = tree[cur].len;
                int linklen = tree[tree[cur].link].len;
                if (i - 1 - curlen >= 0 and s[i - 1 - curlen] == s[i]) {
                    break;
                }
                if (i - 1 - curlen >= 0 and s[i - 1 - curlen] != s[i] and s[i - 1 - linklen] != s[i]) {
                    cur = tree[cur].quicklink;
                } else {
                    cur = tree[cur].link;
                }
            }
            nw.link = tree[cur].next[s[i]];
        }
        int u = nw.link;
        int ud = tree[nw.link].link;
        if (s[i - tree[u].len] == s[i - tree[ud].len]) {
            nw.quicklink = tree[u].quicklink;
        } else {
            nw.quicklink = ud;
        }
        tree.push_back (nw);
        return 1;
    }
};
int main ( ) {
#ifdef LOCAL
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    eertree t1;
    for (int i = 0; i < s.size (); i++) {
        t1.add (i, s);
    }
    cout << s;
    int lps = t1.tree[t1.palsuf].len;
    string s2 = s.substr(0, s.size() - lps);
    reverse(s2.begin(), s2.end());
    if (s2.empty()) {
        lps = t1.tree[t1.tree[t1.palsuf].link].len;
        s2 = s.substr(0, s.size() - lps);
        reverse(s2.begin(), s2.end());
    }
    cout << s2 << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}