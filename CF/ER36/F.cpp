#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

vector<vector<int> > glist;

struct UFDS{
    vector<int> p, rank, size;
    UFDS(int n) {
        p.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int findset(int i) {
        return i == p[i] ? i : p[i] = findset(p[i]);
    }
    bool isSameSet(int a, int b) {
        return findset(a) == findset(b);
    }
    void un(int a, int b) {
        if (!isSameSet(a, b)) {
            int x = findset(a), y = findset(b);
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
            } else {
                p[x] = y;
                size[y] += size[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

};

ll get(const vector<ii> &a) {
    UFDS uf(a.size());
    vector<bool> done(a.size(), false);
    ll ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret += a[i].first;
        for (auto to : glist[a[i].second]) {
            if (!done[to]) {
                continue;
            }
            ret += ((ll)a[i].first * uf.size[uf.findset(a[i].second)] * uf.size[uf.findset(to)]);
            uf.un(a[i].second, to);
        }
        done[a[i].second] = true;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("inb.txt", "r", stdin);
//    freopen("outb.txt", "w", stdout);
    int n;
    cin >> n;
    glist.resize(n);
    vector<ii> a;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(ii(temp, i));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        glist[u].push_back(v);
        glist[v].push_back(u);
    }
    ll mx = get(a);
    reverse(a.begin(), a.end());
    ll mn = get(a);
    cout << mx - mn << "\n";
    return 0;
}
