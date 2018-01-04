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
};
const ll MAXLEN = 250005;
vector<state> st;
ll sz, last;
void sa_init(ll size) {
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
void sa_extend (char c) {
    ll cur = sz++;
    st[cur].cnt = 1;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
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

void constructSA(string ss) {
    sa_init(ss.size());
    for(ll i = 0; i < ss.size(); i++) {
        sa_extend(ss[i]);
    }
}

void smallestcyclicshift(const string ss) {
    ll at = 0;
    string anss;
    ll length = 0;
    while(length != ss.size()) {
        for (auto it : st[at].next) {
            anss.push_back(it.first);
            at = it.second;
            length++;
            break;
        }
    }
    cout << st[at].firstpos - ss.size() + 2LL << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("insam.txt", "r", stdin);
    //freopen("outsam.txt", "w", stdout);
    int tc;
    cin >> tc;
    while(tc--) {
        string inp;
        cin >> inp;
        string nw = inp + inp;
        constructSA(nw);
        smallestcyclicshift(inp);
    }

    return 0;
}
