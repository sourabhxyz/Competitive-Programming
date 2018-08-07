/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

/* Input opener ends */

#define MAX 112345
#define MOD 1000000007
#define SQ 320

int tree[MAX];
// value[n] += x
void add(int n, int x) { for (; n < MAX; n |= n + 1) tree[n] += x; }
// Returns value[0] + value[1] + ... + value[n]
int sum(int n) { int s=0; while (n>=0) { s+=tree[n]; n=(n&(n+1))-1; } return s; }

struct event {
    int l,r,idx,k;
} e[MAX];
bool operator<(event a,event b) {
    if ( a.l/SQ != b.l/SQ ) return a.l/SQ<b.l/SQ;
    else if ( a.r != b.r ) return a.r<b.r;
    return a.idx<b.idx;
}

int T, start[MAX], end[MAX];
int color[MAX], a[MAX];
vector<int> g[MAX];
void dfs(int whr,int par) {
    a[T] = color[whr];
    start[whr] = T++;
    F(i,0,g[whr].size()) {
        int next = g[whr][i];
        if ( next == par ) continue;
        dfs(next,whr);
    }
    end[whr] = T-1;
}
int cnt[MAX] = {0}, ans[MAX];

#define gc getchar
inline void readInt(int &n) {
    n = 0;
    char ch = gc();
    while ( !isdigit(ch) ) ch=gc();
    while ( isdigit(ch) ) {
        n = n*10 + ch-48;
        ch=gc();
    }
}

int main() {
    input();
    int n,q; readInt(n); readInt(q);
    F(i,0,n) readInt(color[i]);
    F(i,1,n) {
        int a,b; readInt(a); readInt(b);
        a--; b--;
        g[a].pb(b); g[b].pb(a);
    } // graph read
    T = 0;
    dfs(0,0); // we know the start and end of each vertex
    F(i,0,q) {
        int a,k; readInt(a); readInt(k); a--;
        e[i].l = start[a]; e[i].r = end[a]; e[i].k = k;
        e[i].idx = i;
        // cout << e[i].l << " " << e[i].r << " " << e[i].k << endl;
    } // queries read
    sort(e,e+q);
    int l = 0, r = 0;
    cnt[a[0]]++;
    add(cnt[a[0]],1);
    F(i,0,q) {
        while ( r < e[i].r ) {
            r++;
            add(cnt[a[r]],-1);
            cnt[a[r]]++;
            add(cnt[a[r]],1);
        }
        while ( r > e[i].r ) {
            add(cnt[a[r]],-1);
            cnt[a[r]]--;
            add(cnt[a[r]],1);
            r--;
        }
        while ( l < e[i].l ) {
            add(cnt[a[l]],-1);
            cnt[a[l]]--;
            add(cnt[a[l]],1);
            l++;
        }
        while ( l > e[i].l ) {
            l--;
            add(cnt[a[l]],-1);
            cnt[a[l]]++;
            add(cnt[a[l]],1);
        }
        ans[e[i].idx] = sum(MAX-5)-sum(e[i].k-1);
    }
    F(i,0,q) printf("%d\n", ans[i]);
    return 0;
}