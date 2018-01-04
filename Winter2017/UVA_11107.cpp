
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
//Learning in depth about suffix automaton.
vector<set<int> > occ;
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
    occ.clear();
    occ.resize(2 * size);
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
    //freopen("inc.txt", "r", stdin);
    //freopen("outc.txt", "w", stdout);
    int n;
    bool first = true;
    while(cin >> n and n) {
        cin.ignore();
        if(first) first = false;
        else cout << "\n";
        vector<string> ss((unsigned int)n);
        sa_init(100005);
        string final;
        set<string> answ;
        for (int i = 0; i < n; i++) {
            getline(cin, ss[i]);
            for (auto c : ss[i]) {
                sa_extend(c, i);
            }
            final += ss[i];
            final += '!';
            sa_extend('!', i);
        }
        for (int v = 1; v < sz; ++v)
            st[st[v].link].inv_link.push_back(v);
        countt.assign(200010, 0);
        dfs(0);
        int k;
        if(n % 2 == 0) {
            k = n / 2 + 1;
        } else {
            k = (n + 2 - 1) / 2;
        }
//        int k = ceil((double)n / 2);
        ll maxlen = 0;
        for(int i = 0; i < n; i++)
        {
            ll index;
            ll v = 0, ln = 0;
            for(auto c : ss[i])
            {
                v = st[v].next[c];
                while(countt[v] < k)
                    v = st[v].link;
                if(ln + 1 > st[v].len) {
                    index = v;
                    ln = st[v].len;
                } else {
                    index = v;
                    ln = ln + 1;
                }
                maxlen = max(ln, maxlen);
            }
        }
        if(maxlen == 0) {
            cout << "?\n";
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            ll index;
            ll v = 0, ln = 0;
            for(auto c : ss[i])
            {
                v = st[v].next[c];
                while(countt[v] < k)
                    v = st[v].link;
                if(ln + 1 > st[v].len) {
                    index = v;
                    ln = st[v].len;
                } else {
                    index = v;
                    ln = ln + 1;
                }
                if(ln == maxlen) {
                    string aa = final.substr((unsigned int)(st[index].firstpos - st[index].len + 1), (unsigned int)ln);
                    answ.insert(aa);
                }
            }

        }
        for (auto astr : answ) {
            cout << astr << "\n";
        }
    }
    return 0;
}
