#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
//Learning in depth about suffix automaton.
struct state {
    int len, link;
    map<char,int> next;
    int cnt;
    int firstpos;
    bool is_clon;
};
const int MAXLEN = 1005;
state st[MAXLEN*2];
int sz, last;
vector<pair<int, int> > tcntdata;
void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].cnt = 0;
    st[0].link = -1;
    st[0].firstpos = -1;
    st[0].is_clon = false;
    ++sz;
    for (int i=0; i<MAXLEN*2; ++i)
        st[i].next.clear();
    tcntdata.clear();
    tcntdata.push_back(ii(0, 0));
}
void sa_extend (char c) {
    int cur = sz++;
    st[cur].cnt = 1;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
    st[cur].is_clon = false;
    tcntdata.push_back(ii(st[cur].len, cur));
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
            st[clone].cnt = 0;
            st[clone].firstpos = st[q].firstpos;
            st[clone].is_clon = true;
            tcntdata.push_back(ii(st[clone].len, clone));
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void processcnt() {
    sort(tcntdata.begin(), tcntdata.end());
    reverse(tcntdata.begin(), tcntdata.end());
    for(auto v : tcntdata) {
        st[st[v.second].link].cnt += st[v.second].cnt;
    }
}

void constructSA(string ss) {
    sa_init();
    for(int i = 0; i < ss.size(); i++) {
        sa_extend(ss[i]);
    }
    processcnt();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        constructSA(s);
        string ans;
        int value = 0;
        for(int i = 0; i < sz; i++) {
            if(st[i].cnt > 1 and st[i].len > value) {
                value = st[i].len;
            }
        }
        vector<int> candidates;
        for(int i = 0; i < sz; i++) {
            if(st[i].len == value and st[i].cnt > 1) {
                candidates.push_back(i);
            }
        }
        string finalans;
        for(int i = 0; i < s.size() + 5; i++) finalans.push_back('z');
        int mark;
        if(value) {
            for(int i = 0; i < candidates.size(); i++) {
                string temp;
                int pos = st[candidates[i]].firstpos - st[candidates[i]].len + 1;
                for(int j = pos, k = 0; k < value; j++, k++) {
                    temp += s[j];
                }
                if(temp < finalans) {
                    mark = candidates[i];
                    finalans = temp;
                }
            }
            cout << finalans << " " << st[mark].cnt << "\n";
        } else {
            cout << "No repetitions found!\n";
        }
    }
    return 0;
}
