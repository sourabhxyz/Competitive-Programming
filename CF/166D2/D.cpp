#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;


map<char, int> chmp;
int lim;

struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 1505;
state st[MAXLEN * 2];
int sz, last;
vector<vector<int> > dp;

void sa_init(unsigned int size) {
    dp.assign(2 * size + 5, vector<int> (size + 5, -1));
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}
void sa_extend (char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void constructSA(string ss) {
    sa_init(ss.size());
    for(int i = 0; i < ss.size(); i++) {
        sa_extend(ss[i]);
    }
}

int numdiffgood(int at, int cnt) {
    if(dp[at][cnt] != -1) return dp[at][cnt];
    dp[at][cnt] = 1;
    for(auto to : st[at].next) {
        if (chmp[to.first]) {
            if (cnt + 1 <= lim) {
                dp[at][cnt] += numdiffgood(to.second, cnt + 1);
            }
        } else {
            dp[at][cnt] += numdiffgood(to.second, cnt);
        }
    }
    return dp[at][cnt];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    string given;
    cin >> given;
    constructSA(given);
    cin >> given;
    for (int i = 0; i < 26; i++) {
        chmp[97 + i] = 1 - (given[i] - 48);
    }
    cin >> lim;
    cout << numdiffgood(0, 0) - 1 << "\n";
    return 0;
}
