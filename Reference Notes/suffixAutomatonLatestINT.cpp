#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int int;
//Learning in depth about suffix automaton.
struct state {
    int len, link;
    map<char,int> next;
    int cnt;
    int firstpos;
    bool is_clon;
    vector<int> inv_link;
};
const int MAXLEN = 250005;
vector<state> st;
int sz, last;
vector<vector<int> > tcntdata;
vector<int> nsubs, d, lw;
vector<bool> isterminal;
void sa_init(unsigned int size) {
    nsubs.assign(2 * size, 0);
    isterminal.assign(2 * size, false);
    tcntdata.clear();
    tcntdata.resize(2 * size);
    lw.assign(2 * size, 0);
    d.assign(2 * size, 0);
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
    int cur = sz++;
    st[cur].cnt = 1;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
    st[cur].is_clon = false;
    tcntdata[st[cur].len].push_back(cur);
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1) // In case we came to the root, every non-empty suffix of string sc is accepted by state cur hence we can make link(cur) = t0 and finish our work on this step.
        st[cur].link = 0;
    else {  // Otherwise we found such state q`, which already has transition by character c. It means that all suffixes of length ≤ len(q`) + 1 are already accepted by some state in automaton hence we don’t need to add transitions to state new anymore. But we also have to calculate suffix link for state new.
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)  // The largest string accepted by this state will be suffix of sc of length len(q`) + 1. It is accepted by state t at the moment, in which there is transition by character c from state q`. But state t can also accept strings of bigger length. So, if len(t) = len(q`) + 1, then t is the suffix link we are looking for. We make link(cur) = t and finish algorithm.
            st[cur].link = q;
        else {
            int clone = sz++;
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
    int maxlen = st[last].len;
    for(int i = maxlen; i >= 0; i--) {
        for(auto v : tcntdata[i]) {
            st[st[v].link].cnt += st[v].cnt;
        }
    }
}
void processterminal() {
    isterminal[last] = true;
    int p = st[last].link;
    while(p != -1) {
        isterminal[p] = true;
        p = st[p].link;
    }
}

int processnumsubs(int at) {
    if(nsubs[at] != 0) return nsubs[at];
    nsubs[at] = st[at].cnt;
    for(auto to : st[at].next) {
        nsubs[at] += processnumsubs(to.second);
    }
    return nsubs[at];
}

void constructSA(string ss) {
    sa_init(ss.size());
    for(int i = 0; i < ss.size(); i++) {
        sa_extend(ss[i]);
    }
    processterminal();
    processcnt();
    for (int v = 1; v < sz; ++v)
        st[st[v].link].inv_link.push_back(v);
    processnumsubs(0);
}

bool exist(string &tosearch) {
    int at = 0;
    for (int i = 0; i < tosearch.size(); i++) {
        if (!st[at].count (tosearch[i])) return false;
        at = st[at].next[tosearch[i]];
    }
    return true;
}

//Returns number of different substrings
int numdiffsub(int at) {
    if(d[at] != 0) return d[at];
    d[at] = 1;
    for(auto to : st[at].next) {
        d[at] += numdiffsub(to.second);
    }
    return d[at];
}

//Returns total length of various substrings
int totlength(int at) {
    if(lw[at] != 0) return lw[at];
    for(auto to : st[at].next) {
        lw[at] += d[to.second] + totlength(to.second);
    }
    return lw[at];
}

//Find Lexicographically K-th Substring (here repeated substring is allowed):
void kthlexo(int at, int k, string &as) {
    if(k <= 0) return;
    for(auto to : st[at].next) {
        if(nsubs[to.second] >= k) {
            as.push_back(to.first);
            kthlexo(to.second, k - st[to.second].cnt, as);
            break;
        } else {
            k -= nsubs[to.second];
        }
    }
}
//Repeated substring not allowed
void kthlexo2(int at, int k, string &as) {
    if(k <= 0) return;
    for(auto to : st[at].next) {
        if(d[to.second] >= k) {
            as.push_back(to.first);
            kthlexo(to.second, k - 1, as);
            break;
        } else {
            k -= d[to.second];
        }
    }
}
//Returns true is the given string is the suffix of T
bool issuffix(string tosearch) {
    int at = 0;
    for (int i = 0; i < tosearch.size(); i++) {
        if(st[at].next.find(tosearch[i]) == st[at].next.end()) {
            return false;
        }
        at = st[at].next[tosearch[i]];
    }
    if(isterminal[at]) return true;
    else return false;
}

//Returns how many times P enters in T (occurences can overlap)
/*for each state v of the machine calculate a number 'cnt[v]' which is equal to the
 * size of the set endpos(v). In fact, aint the rows corresponding to the same state
 * enter the T same number of times which is equal to the number of positions in the set
 * endpos. */
int numoccur(string tosearch) {
    int at = 0;
    for (int i = 0; i < tosearch.size(); i++) {
        if(st[at].next.find(tosearch[i]) == st[at].next.end()) {
            return 0;
        }
        at = st[at].next[tosearch[i]];
    }
    return st[at].cnt;
}

//Return position of the first occurrence of substring in T
int firstpos(string tosearch) {
    int at = 0;
    for (int i = 0; i < tosearch.size(); i++) {
        if(st[at].next.find(tosearch[i]) == st[at].next.end()) {
            return -1;
        }
        at = st[at].next[tosearch[i]];
    }
    return st[at].firstpos - tosearch.size() + 1;

}
//Returns Positions of aint occurrences of substring in T
int getcorrstate(string tosearch) {
    int at = 0;
    for (int i = 0; i < tosearch.size(); i++) {
        if(st[at].next.find(tosearch[i]) == st[at].next.end()) {
            return -1;
        }
        at = st[at].next[tosearch[i]];
    }
    return at;
}
void output_all_occurences (int v, int P_length) {
    if (!st[v].is_clon)
        cout << st[v].firstpos - P_length + 1 << "\n";
    for (size_t i=0; i<st[v].inv_link.size(); ++i)
        output_all_occurences(st[v].inv_link[i], P_length);
}

void smallestcyclicshift(const string ss) {
    int at = 0;
    string anss;
    int length = 0;
    while(length != ss.size()) {
        for (auto it : st[at].next) {
            anss.push_back(it.first);
            at = it.second;
            length++;
            break;
        }
    }
    cout << st[at].firstpos - ss.size() + 2 << "\n";
}


int main() {
    string s;
    cin >> s;
    constructSA(s);
    int choice;
    while(true){
        cout << "Choose your option:\n1: Substring exist in T or not\n2: Number of different substring of T\n";
        cout << "3: To find total length of various substrings\n";
        cout << "4: To check whether the given string is suffix or not\n";
        cout << "5(5.1): To print the K-th lexicographic substring (Repeated substrings allowed)\n";
        cout << "6: To see how many times, given string occurs in T\n";
        cout << "7: To find the position of the first occurrence of substring in T\n";
        cout << "8: To find position of all the occurences of substring in T\n";
        cout << "9(5.2): To print the K-th lexicographic substring (Repeated substrings not allowed)\n";
        cout << "10: To find the smallest cyclic shift\n";

        cout << "15: to exit\n";
        cin >> choice;
        if(choice == 15) break;
        string ss, ns;
        int k, v;
        switch(choice) {
            case 1:
                cout << "Enter your string\n";
                cin >> ss;
                if (exist(ss)) {
                    cout << "yes it exist\n";
                } else {
                    cout << "no it does not exist\n";
                }
                //cout << "Enter new to string to search for\n";
                break;
            case 2:
                cout << numdiffsub(0) - 1 << "\n";
                break;
            case 3:
                numdiffsub(0);
                cout << totlength(0) << "\n";
                break;
            case 4:
                cout << "Enter the string\n";
                cin >> ss;
                if(issuffix(ss)) cout << "yes\n";
                else cout << "no\n";
                break;
            case 5:
                cin >> k;
                ss.clear();
                kthlexo(0, k, ss);
                if(ss.empty()) {
                    ss = "No such line.";
                }
                cout << ss << "\n";
                break;
            case 6:
                cout << "Enter string\n";
                cin >> ss;
                cout << numoccur(ss) << "\n";
                break;
            case 7:
                cout << "Enter string\n";
                cin >> ss;
                cout << firstpos(ss) << "\n";
                break;
            case 8:
                cout << "Enter string\n";
                cin >> ss;
                /*for(v = 0; v < s.size(); v++) {
                    cout << setw(2) << v;
                }
                cout << "\n";
                for(v = 0; v < s.size(); v++) {
                    cout << setw(2) << s[v];
                }
                cout << "\n";*/
                v = getcorrstate(ss);
                if(v != -1) {
                    output_all_occurences(v, ss.size());
                }
                break;
            case 9:
                cin >> k;
                ss.clear();
                numdiffsub(0);
                kthlexo2(0, k, ss);
                if(ss.empty()) {
                    ss = "No such line.";
                }
                cout << ss << "\n";
                break;
            case 10:
                cout << "Enter S\n";
                cin >> ss;
                s = ss + ss;
                constructSA(s);
                smallestcyclicshift(ss);
                break;
        }
    }
    return 0;
}
