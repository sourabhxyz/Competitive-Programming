#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int maxn = 1e5 + 5;
const int xlimit = 1e9 + 5;
map<string, int> sid;

struct node{
    node *l, *r;
    int val;
    node() {
        l = NULL, r = NULL, val = 0;
    }
};

node *sidp[maxn], *pt[maxn];

node *upd1(node *p, int &id, int al, int ar, int val) {
    if (!p) p = new node();
    if (id < al || id > ar) {
        return p;
    }
    if (al == ar) {
        node *res = new node();
        res->val = val;
        return res;
    }
    node *res = new node();
    int mid = (al + ar) / 2;
    res->l = upd1(p->l, id, al, mid, val);
    res->r = upd1(p->r, id, mid + 1, ar, val);
    return res;
}

node *upd2(node *p, int &pri, int al, int ar, int up) {
    if (!p) p = new node();
    if (pri < al || pri > ar) {
        return p;
    }
    if (al == ar) {
        node *res = new node();
        res->val = p->val + up;
        return res;
    }
    node *res = new node();
    int mid = (al + ar) / 2;
    res->l = upd2(p->l, pri, al, mid, up);
    res->r = upd2(p->r, pri, mid + 1, ar, up);
    res->val = res->l->val + res->r->val;
    return res;
}

int query(node *p, int rl, int rr, int al, int ar) {
    if (!p) p = new node();
    if (ar < rl || al > rr) return 0;
    if (al >= rl and ar <= rr) return p->val;
    int mid = (al + ar) / 2;
    return (query(p->l, rl, rr, al, mid) + query(p->r, rl, rr, mid + 1, ar));
}

int getid(string &given) {
    if (sid.count(given)) {
        return sid[given];
    } else {
        return sid[given] = sid.size();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    int q;
    cin >> q;
    for (int day = 1; day <= q; day++) {
        string op;
        cin >> op;
        if (op == "set") {
            string a; int x;
            cin >> a >> x;
            int id = getid(a);
            sidp[day] = upd1(sidp[day - 1], id, 0, maxn - 1, x); //Just a copy with new priority
            int px = query(sidp[day - 1], id, id, 0, maxn - 1);
            if (px) { //Means that 'a' already exists.
                pt[day] = upd2(pt[day - 1], px, 0, xlimit, -1);
            } else {
                pt[day] = pt[day - 1];
            }
            pt[day] = upd2(pt[day], x, 0, xlimit, 1);
        } else if (op == "remove") {
            string a;
            cin >> a;
            int id = getid(a);
            sidp[day] = upd1(sidp[day - 1], id, 0, maxn - 1, 0);
            int px = query(sidp[day - 1], id, id, 0, maxn - 1);
            if (px) {
                pt[day] = upd2(pt[day - 1], px, 0, xlimit, -1);
            }
            else {
                pt[day] = pt[day - 1];
            }
        }
        else if (op == "undo") {
            int dec;
            cin >> dec;
            sidp[day] = sidp[day - dec - 1];
            pt[day] = pt[day - dec - 1];
        }
        else if (op == "query") {
            string a; cin >> a;
            int id = getid(a);
            int x = query(sidp[day] = sidp[day - 1], id, id, 0, maxn - 1);
            pt[day] = pt[day - 1];
            if (!x) {
                cout << -1 << "\n";
            }
            else {
                cout << query(pt[day] = pt[day - 1], 0, x - 1, 0, xlimit) << "\n";
            }
            cout << flush;
        }
    }
    return 0;
}
