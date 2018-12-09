#include <bits/stdc++.h>
using namespace std;


struct state {
    int link, len, firstpos;
    map<char, int> trans;
};

vector<state> sa;
int last,cnt,n,maxlen,req;
char delim[105];
map<char,int> Delim;
string T,P,cur;
vector<set<int> > occ;
set<string> ans;

void sa_init(int tot) {
    occ.clear();
    sa.clear();
    sa.resize(2*tot);
    occ.resize(2*tot);
    sa[0].len = 0, sa[0].link = -1;
    sa[0].firstpos = -1;
    last = 0, cnt = 1;
}

void sa_extend(char c) {
    int cur = cnt++, p = last, q;
    sa[cur].len = sa[p].len + 1;
    sa[cur].firstpos = sa[cur].len - 1;
    for (; p != -1 && !sa[p].trans.count(c); p = sa[p].link)
        sa[p].trans[c] = cur;
    if (p == -1) sa[cur].link = 0;
    else {
        q = sa[p].trans[c];
        if (sa[q].len == sa[p].len + 1) sa[cur].link = q;
        else {
            int clone = cnt++;
            sa[clone].len = sa[p].len + 1;
            sa[clone].firstpos = sa[q].firstpos;
            sa[clone].link = sa[q].link, sa[clone].trans = sa[q].trans;
            for (; p != -1 && sa[p].trans[c] == q; p = sa[p].link)
                sa[p].trans[c] = clone;
            sa[q].link = sa[cur].link = clone;
        }
    }
    last = cur;
}

void DFSfill(int u) {
    if (!occ[u].empty()) return;  // base case, getting one delimeter and we stop.
    for (auto i:sa[u].trans) {
        DFSfill(i.second);
        for (auto j:occ[i.second])
            occ[u].insert(j);
    }
    int totocc = occ[u].size();
    if (totocc >= req && sa[u].len > maxlen) maxlen = sa[u].len;
    return;
}


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool ch = false;
    for (int i = 0, j = 0; i < 101; i++, j++) {
        if (j == 'a') j += 26;
        delim[i] = j;
        Delim[j] = i;
    }
    while (cin >> n, n) {
        if (ch) cout << endl;
        else ch = true;
        T = "", maxlen = 0;
        req = (n >> 1) + 1;
        for (int i = 0; i < n; i++)
            cin >> P, T += (P + delim[i]);
        sa_init(T.length());
        for (auto i:T) {
            sa_extend(i);
            if (!islower(i))
                occ[last].insert(Delim[i]);
        }
        DFSfill(0);
        if(!maxlen) {
            cout<<"?\n";
            continue;
        }
        ans.clear();
        for (int i = 1; i < cnt; i++) {
            if (occ[i].size() >= req && sa[i].len == maxlen) {
                ans.insert(T.substr(sa[i].firstpos - sa[i].len + 1, sa[i].len));
            }
        }
        for(auto i:ans)
            cout<<i<<endl;
    }
    return 0;
}