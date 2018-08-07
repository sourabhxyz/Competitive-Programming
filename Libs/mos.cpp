#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sum = 0;
const int N = 2e6;
const int lim = 1e6;
#define itn int
int cnt[lim], a[N], BLOCK;
ll ans[N];
struct node {
    int L, R, i;
} q[N];

bool cmp(node &x, node &y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

void add(int position) {
    sum += (2 * cnt[a[position]] + 1) * a[position];
    cnt[a[position]]++;
}

void remove(int position) {
    sum = sum - (2 * cnt[a[position]] - 1) * a[position];
    cnt[a[position]]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    BLOCK = (int)sqrt(n) + 1;
    for (itn i = 0; i < t; i++) {
        cin >> q[i].L >> q[i].R;
        q[i].L--; q[i].R--;
        q[i].i = i;
    }
    sort(q, q + t, cmp);
    int currentL = 0, currentR = 0;
    for(int i=0; i<t; i++) {
        int L = q[i].L, R = q[i].R;
        while(currentL < L) {
            remove(currentL);
            currentL++;
        }
        while(currentL > L) {
            add(currentL-1);
            currentL--;
        }
        while(currentR <= R) {
            add(currentR);
            currentR++;
        }
        while(currentR > R+1) {
            remove(currentR-1);
            currentR--;
        }
        ans[q[i].i] = sum;
    }

    for(int i=0; i<t; i++)
        cout << ans[i] << "\n";
}