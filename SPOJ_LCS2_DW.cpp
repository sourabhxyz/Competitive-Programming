#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
//Learning in depth about suffix automaton.
const int maxn = 2000005;
set<int> occ[maxn];
struct state {
    ll len, link;
    map<char,ll> next;
    ll cnt;
    ll firstpos;
    bool is_clon;
    vector<int> inv_link;
};
vector<state> st;
ll sz, last;
void sa_init(unsigned int size) {
    st.clear();
    st.resize(2 * size);
    sz = last = 0;
    st[0].len = 0;
    st[0].cnt = 0;
    st[0].link = -1;
    st[0].firstpos = -1;
    st[0].is_clon = false;
    ++sz;
}
void sa_extend (char c, int k) {
    ll cur = sz++;
    st[cur].cnt = 1;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
    occ[cur].insert(k);
    st[cur].is_clon = false;
    ll p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        ll q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            ll clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].cnt = 0;
            st[clone].firstpos = st[q].firstpos;
            st[clone].is_clon = true;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

vector<ll> countt;

void dfs(int v)
{
    for(auto u : st[v].inv_link)
    {
        dfs(u);
        if(occ[v].size() < occ[u].size())
            swap(occ[u], occ[v]);
        for(auto it: occ[u])
            occ[v].insert(it);
    }
    countt[v] = occ[v].size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    int n = 0;
    vector<string> ss(11);
    sa_init(1000005);
    while(getline(cin, ss[n++])) {
        for (auto c : ss[n - 1]) {
            sa_extend(c, n - 1);
        }
        sa_extend('!', n - 1);
    }
    n--;
    for (int v = 1; v < sz; ++v)
        st[st[v].link].inv_link.push_back(v);
    countt.assign(2000005, 0);
    dfs(0);
    ll value = 0;
    for(int i = 0; i < sz; i++) {
        if(countt[i] == n and st[i].len > value) {
            value = st[i].len;
        }
    }
    cout << value << "\n";
    return 0;
}
