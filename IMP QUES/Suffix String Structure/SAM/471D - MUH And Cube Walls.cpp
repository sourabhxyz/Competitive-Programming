#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct state {
    int len, link, cnt;
    map<int, int> next;
};

state st[4 * 100000 + 5];
int sz, lst;
vector<int> tcntdata[4 * 100000 + 5];

void add(int c) {
    int cur = sz++;
    st[cur].len = st[lst].len + 1;
    st[cur].cnt = 1;
    tcntdata[st[cur].len].push_back(cur);
    int p;
    for (p = lst; p != -1 and !st[p].next.count(c); p = st[p].link) {
        st[p].next[c] = cur;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[q].len == st[p].len + 1) {
            st[cur].link = q;
        } else {
            int cln = sz++;
            st[cln].cnt = 0;
            st[cln].len = st[p].len + 1;
            tcntdata[st[cln].len].push_back(cln);
            st[cln].next = st[q].next;
            st[cln].link = st[q].link;
            for (; p != -1 and st[p].next[c] == q; p = st[p].link) {
                st[p].next[c] = cln;
            }
            st[q].link = st[cur].link = cln;
        }
    }
    lst = cur;
}

void processcnt() {
    int mx = st[lst].len;
    for (int i = mx; i >= 1; i--) {
        for (auto v : tcntdata[i]) {
            st[st[v].link].cnt += st[v].cnt;
        }
    }
//    st[0].cnt = 0;
}

void construct(vector<int> &s) {
    st[0].len = 0; st[0].cnt = 0; st[0].link = -1;
    sz = 1; lst = 0;
    for (auto c : s) {
        add(c);
    }
    processcnt();
}

int getcorrstate(vector<int> &tosearch) {
    int at = 0;
    for (int i = 0; i < tosearch.size(); i++) {
        if(st[at].next.find(tosearch[i]) == st[at].next.end()) {
            return -1;
        }
        at = st[at].next[tosearch[i]];
    }
    return at;
}

int n, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     freopen("ina.txt", "r", stdin);
     freopen("outa.txt", "w", stdout);
    cin >> n >> w;
    if (w == 1) {
        cout << n << "\n";
        return 0;
    }
    vector<int> get(n);
    for (int i = 0; i < n; i++) {
        cin >> get[i];
    }
    string s;
    for (int i = 0; i < n - 1; i++) {
        get[i] = get[i] - get[i + 1];
    }
    get.pop_back();
    construct(get);
    get.clear();
    get.resize(w);
    for (int i = 0; i < w; i++) {
        cin >> get[i];
    }
    for (int i = 0; i < w - 1; i++) {
        get[i] = get[i] - get[i + 1];
    }
    get.pop_back();
    int corrst = getcorrstate(get);
    cout << st[corrst].cnt << "\n";
    return 0;
}