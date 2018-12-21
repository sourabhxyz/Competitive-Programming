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
char s[5000005];
char output[5000005];
struct estatse {
    int len, link;
    int next[2];
    estatse () { next[0] = next[1] = 0; }
};
estatse tree[5000005];
int palsuf, siz;
// 0 is imaginary node, 1 is epsilon node
void init () {
    siz = 2;
    tree[0].len = -1;
    tree[0].link = 0;
    tree[1].len = 0;
    tree[1].link = 0;
    palsuf = 1;
}
int add (int &i) {
    int cur = palsuf;
    while (true) {
        int curlen = tree[cur].len;
        if (i - 1 - curlen >= 0 and s[i - 1 - curlen] == s[i]) break;
        cur = tree[cur].link;
    }
    if (tree[cur].next[s[i] - 'a']) {
        palsuf = tree[cur].next[s[i] - 'a'];
        return 0;
    }
    siz++;
    palsuf = siz - 1;
    estatse nw;
    tree[cur].next[s[i] - 'a'] = siz - 1;
    nw.len = tree[cur].len + 2;
    if (nw.len == 1) {
        nw.link = 1;
    } else {
        cur = tree[cur].link;
        while (true) {
            int curlen = tree[cur].len;
            if (i - 1 - curlen >= 0 and s[i - 1 - curlen] == s[i]) {
                break;
            }
                cur = tree[cur].link;
        }
        nw.link = tree[cur].next[s[i] - 'a'];
    }
    int u = nw.link;
    int ud = tree[nw.link].link;
    tree[siz - 1] = nw;
    return 1;
}
int main ( ) {
#ifdef LOCAL
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    scanf("%s", s);
    int n = strlen (s);
    init ();
    for (int i = 0; i < n; i++) {
        output[i] = add (i) + 48;
    }
    puts (output);
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}