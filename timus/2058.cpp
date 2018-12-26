#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
    #pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
    #pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
#endif
typedef long long int ll;
typedef pair<int, int> ii;
const int inf = 100000000;
const double eps = 1e-12;
const int maxn = 300005;
struct estatse {
    int len, quicklink, link, serieslink, diff;
    map<int, int> next;
    estatse () { }
};
struct eertree {
    int palsuf, siz;
    vector<estatse> tree;
    // 0 is imaginary node, 1 is epsilon node
    eertree (int n) {
        siz = 2;
        tree.resize (2 + n);
        tree[0].len = -1;
        tree[0].link = 0;
        tree[0].quicklink = 0;
        tree[0].serieslink = 0;
        tree[0].diff = 0;
        tree[1].len = 0;
        tree[1].link = 0;
        tree[1].quicklink = 0;
        tree[1].serieslink = 0;
        tree[1].diff = 0;
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
        nw.diff = nw.len - tree[nw.link].len;
        if (nw.diff == tree[nw.link].diff) {
            nw.serieslink = tree[nw.link].serieslink;
        } else {
            nw.serieslink = nw.link;
        }
        tree[siz - 1] = nw;
//        tree.push_back (nw);
        return 1;
    }
};
int anso[maxn], anse[maxn], dpo[maxn], dpe[maxn], palsuf[maxn];
ii getMin (int &v, eertree &t, int n) {
    dpo[v] = anso[n - (t.tree[t.tree[v].serieslink].len + t.tree[v].diff)];
    dpe[v] = anse[n - (t.tree[t.tree[v].serieslink].len + t.tree[v].diff)];
    if (t.tree[v].diff == t.tree[t.tree[v].link].diff) {
        dpo[v] = min (dpo[v], dpo[t.tree[v].link]);
        dpe[v] = min (dpe[v], dpe[t.tree[v].link]);
    }
    return ii (dpo[v] + 1, dpe[v] + 1);
}
int main ( ) {
#ifdef LOCAL
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    eertree t1 (s.size ());
    anso[0] = inf;
    anse[0] = 0;
    dpe[0] = dpe[1] = dpo[0] = dpo[1] = 0;
    for (int i = 0; i < s.size (); i++) {
        t1.add (i, s);
        palsuf[i + 1] = t1.palsuf;
        anso[i + 1] = inf;
        anse[i + 1] = inf;
        for (int v = t1.palsuf; t1.tree[v].len > 0; v = t1.tree[v].serieslink) {
            auto temp = getMin (v, t1, i + 1);
            anso[i + 1] = min (anso[i + 1], temp.second);
            anse[i + 1] = min (anse[i + 1], temp.first);
        }
        anso[i + 1] != inf ? cout << anso[i + 1] : cout << "-1";
        cout << " ";
        anse[i + 1] != inf ? cout << anse[i + 1] : cout << "-2";
        cout << "\n";
    }
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}