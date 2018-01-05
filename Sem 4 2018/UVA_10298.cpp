#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
//Learning in depth about suffix automaton.
struct state {
    int len, link;
    map<char,int> next;
    int cnt;
    int firstpos;
    bool is_clon;
    vector<int> inv_link;
};
state st[3000005];
int sz, last;
vector<int> tcntdata[3000005];
void sa_init(unsigned int size) {
//    tcntdata.clear();
//    tcntdata.resize(size + 5);
    for (int i = 0; i <= 3 * size; i++) {
        tcntdata[i].clear();
        st[i].next.clear();
        st[i].inv_link.clear();
    }
//    for (int i = 0; i <= 3 * size; i++) {
//        st[i].next.clear();
//    }
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
    int cur = sz++;
    st[cur].cnt = 1;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
    st[cur].is_clon = false;
    tcntdata[st[cur].len].push_back(cur);
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
            st[clone].is_clon = true;
            st[clone].firstpos = st[q].firstpos;
            tcntdata[st[clone].len].push_back(clone);
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void processcnt() {
    int maxlen = st[last].len;
    for(int i = maxlen; i > 0; i--) {
        for(auto v : tcntdata[i]) {
            st[st[v].link].cnt += st[v].cnt;
        }
    }
}

void constructSA(string ss) {
    sa_init(ss.size());
    for(int i = 0; i < ss.size(); i++) {
        sa_extend(ss[i]);
    }
    processcnt();
    for (int v = 1; v < sz; ++v)
        st[st[v].link].inv_link.push_back(v);
}
void output_all_occurences (int v, int P_length, vector<ii> &occur) {
    if (!st[v].is_clon)
        occur.push_back(ii(st[v].firstpos - P_length + 1, st[v].firstpos));
    for (size_t i=0; i<st[v].inv_link.size(); ++i)
        output_all_occurences(st[v].inv_link[i], P_length, occur);
}
bool alloccurdiff(int at, int len) {
    vector<ii> occur;
    output_all_occurences(at, len, occur);
    int pss = occur[0].first, pee = occur[0].second;
    for (int i = 1; i < occur.size(); i++) {
        int ss = occur[i].first, ee = occur[i].second;
        if (ss <= pee) {
            return false;
        }
        pss = ss;
        pee = ee;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    string as;
    while (getline(cin, as) and as[0] != '.') {
//        cin >> as;
        constructSA(as);
        int ln = as.size();
        int finalcnt = 0;
        string wrong;
        for (int i = 1; i < sz; i++) {
            /*if (st[i].cnt * st[i].len == ln) {
                finalcnt = st[i].cnt;
                wrong = as.substr(st[i].firstpos - st[i].len + 1, st[i].len);
                break;
            }*/
            if ((st[i].cnt * st[i].len >= ln) and ((st[st[i].link].len + 1) * st[i].cnt <= ln)) {
                int lll = st[st[i].link].len + 1;
                for (; lll <= st[i].len; lll++) {
                    if (lll * st[i].cnt == ln) {
                        if (lll == 1 || alloccurdiff(i, lll)) {
                            finalcnt = st[i].cnt;
                            i = sz;
                            break;
                        }
                    }
                }

//                finalcnt = max(finalcnt, st[i].cnt);
//                break;
            }
        }
//        cout << wrong << "\n";
        cout << finalcnt << "\n";
    }
    return 0;
}
