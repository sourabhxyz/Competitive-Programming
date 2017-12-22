#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000
const double PI = 2 * acos(0);
const int maxn = 1024000;

int left (int p) { return p << 1; } // same as binary heap operations
int right(int p) { return (p << 1) + 1; }
struct node{
    int type, length;
};

node tree[4 * maxn];
int lazy[4 * maxn];
string final;
const bool debug = false;

void build(int p, int start, int end) { // O(n)
    if (start == end) {// as L == R, either one is fine
        tree[p].type = final[start] - 48;
        tree[p].length = 1;
    } else { // recursively compute the values
        build(left(p) , start , (start + end) / 2);
        build(right(p), (start + end) / 2 + 1, end);
        tree[p].type = tree[left(p)].type + tree[right(p)].type;
        tree[p].length = end - start + 1;
    }
}

void modify(int at, int start, int end) {
    if(lazy[at] == 1) {
        tree[at].type = tree[at].length;
    }
    if(lazy[at] == 2) {
        tree[at].type = 0;
    }
    if(lazy[at] == 3) {
        tree[at].type = tree[at].length - tree[at].type;
        if(lazy[left(at)] != 0) {
            modify(left(at), start, (start + end) / 2);
        }
        if(lazy[right(at)] != 0) {
            modify(right(at), (start + end) / 2 + 1, end);
        }
    }
    if(start != end) {

        lazy[left(at)] = lazy[at];
        lazy[right(at)] = lazy[at];
    }
    lazy[at] = 0;
}

int query(int at, int start, int end, int l, int r) {
    if(r < start || end < l || start > end) return 0;
    if(lazy[at] != 0) {
        modify(at, start, end);
    }
    if(start >= l and end <= r) {
        return tree[at].type;
    }
    int mid = (start + end) / 2;
    int a1 = query(left(at), start, mid, l, r);
    int a2 = query(right(at), mid + 1, end, l, r);
    return a1 + a2;
}

void update(int at, int start, int end, int l, int r, int tt) {
    if(lazy[at] != 0) {
        modify(at, start, end);
    }
    if(r < start || end < l || start > end) return;
    if(start == end) {
        lazy[at] = tt;
        modify(at, start, end);
        return;
    }
    if(start >= l and end <= r) {
        lazy[at] = tt;
        modify(at, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(left(at), start, mid, l, r, tt);
    update(right(at), mid + 1, end, l, r, tt);
    tree[at].type = tree[left(at)].type + tree[right(at)].type;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(2);
    int cases;
    cin >> cases;
    for(int tc = 1; tc <= cases; tc++) {
        cout << "Case " << tc << ":\n";
        int m;
        final.clear();
        cin >> m; //buccanner is 1
        int n = 0;
        for(int i = 0; i < 4 * maxn; i++) lazy[i] = 0;
        for(int i = 0; i < m; i++) {
            int rep;
            cin >> rep;
            string temp;
            cin >> temp;
            while(rep--) {
                n += temp.length();
                final += temp;
            }
        }
        build(1, 0, n - 1);
        
        map<char, int> mp;
        mp['F'] = 1;
        mp['E'] = 2;
        mp['I'] = 3;
        int queries;
        cin >> queries;
        int godq = 1;
        while(queries--) {
            char c;
            cin >> c;
            int l, r;
            cin >> l >> r;
            if(mp.find(c) != mp.end()) {
                update(1, 0, n - 1, l, r, mp[c]);
                
            } else {
                cout << "Q" << godq++ << ": " << query(1, 0, n - 1, l, r) << '\n';
            }
        }
    }
    return 0;

}
