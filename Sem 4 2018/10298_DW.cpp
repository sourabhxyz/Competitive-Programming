#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
//Learning in depth about suffix automaton.
struct state {
    ll len, link;
    map<char,ll> next;
    ll cnt;
    ll firstpos;
    bool is_clon;
    vector<ll> inv_link;
};
vector<state> st;
ll sz, last;
vector<vector<ll> > tcntdata;
vector<bool> isterminal;
void sa_init(unsigned int size) {
    isterminal.assign(2 * size, false);
    tcntdata.clear();
    tcntdata.resize(2 * size);
    st.clear();
    st.resize(2 * size);
    sz = last = 0;
    st[0].len = 0;
    st[0].cnt = 0;
    st[0].link = -1;
    st[0].firstpos = -1;
    st[0].is_clon = false;
    ++sz;
    tcntdata[0].push_back(0);
}
void sa_extend (char c) {
    ll cur = sz++;
    st[cur].cnt = 1;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
    st[cur].is_clon = false;
    tcntdata[st[cur].len].push_back(cur);
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
            tcntdata[st[clone].len].push_back(clone);
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void processcnt() {
    ll maxlen = st[last].len;
    for(ll i = maxlen; i >= 0; i--) {
        for(auto v : tcntdata[i]) {
            st[st[v].link].cnt += st[v].cnt;
        }
    }
}
void processterminal() {
    isterminal[last] = true;
    ll p = st[last].link;
    while(p != -1) {
        isterminal[p] = true;
        p = st[p].link;
    }
}

void constructSA(string ss) {
    sa_init(ss.size());
    for(ll i = 0; i < ss.size(); i++) {
        sa_extend(ss[i]);
    }
    processterminal();
    processcnt();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("inb.txt", "r", stdin);
//    freopen("outb.txt", "w", stdout);
    string as;
    while (cin >> as and as[0] != '.') {
//        cin >> as;
        constructSA(as);
        ll ln = as.size();
        ll finalcnt = 0;
        for (ll i = 0; i < sz; i++) {
            if (st[i].cnt * st[i].len == ln) {
                finalcnt = st[i].cnt;
                break;
            }
        }
        cout << finalcnt << "\n";
    }
    return 0;
}
