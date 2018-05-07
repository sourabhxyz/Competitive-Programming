#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct seg {
    int a, b, c;
};
seg st[4000000];
string inp;
int left(int at) { return 2 * at; }
int right(int at) {return 2 * at + 1; }
void build(int at, int start, int end) {
    if (start == end) {
        st[at].a = 0;
        if (inp[start] == '(') { st[at].b = 1; st[at].c = 0; }
        else { st[at].c = 1; st[at].b = 0; }
    } else {
        int mid = (start + end) >> 1;
        build(left(at), start, mid);
        build(right(at), mid + 1, end);
        int temp = min(st[left(at)].b, st[right(at)].c);
        st[at].a = (st[left(at)].a + st[right(at)].a + temp);
        st[at].b = (st[left(at)].b + st[right(at)].b - temp);
        st[at].c = (st[left(at)].c + st[right(at)].c - temp);
    }
}

seg query(int at, int start, int end, int l, int r) {
    if (l > end || r < start || l > r) return st[0];
    if (start >= l and end <= r) return st[at];
    int mid = (start + end) >> 1;
    seg lf = query(left(at), start, mid, l, r);
    seg ri = query(right(at), mid + 1, end, l, r);
    int temp = min(lf.b, ri.c);
    seg ret;
    ret.a = lf.a + ri.a + temp;
    ret.b = lf.b + ri.b - temp;
    ret.c = lf.c + ri.c - temp;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    cin >> inp;
    int n;
    cin >> n;
    build(1, 0, inp.size() - 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << 2 * query(1, 0, inp.size() - 1, l, r).a << "\n";
    }
   return 0;
}