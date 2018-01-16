#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define inf 10000000

vector<vector<int> > glist;
int farthest, root, bottom, n;
vector<bool> diam;
vector<int> p;
vector<int> dist;

int bfs(int u) {
    queue<int> q;
    q.push(u);
    dist.assign(n, inf);
    dist[u] = 0;
    while (!q.empty()) {
        int at = q.front(); q.pop();
        for (auto to : glist[at]) {
            if (dist[to] == inf) {
                p[to] = at;
                dist[to] = dist[at] + 1;
                farthest = to;
                q.push(to);
            }
        }

    }
    return dist[farthest];
}
vector<tuple<int, int, int> > ops;
vector<ii> rdist;
ii getdist(int at) {
    if (rdist[at].first == -1) {
       if (diam[at]) {
           if (dist[at] > dist[bottom] - dist[at]) {
               rdist[at].first = dist[at];
               rdist[at].second = root;
           } else {
               rdist[at].first = dist[bottom] - dist[at];
               rdist[at].second = bottom;
           }
       } else {
           auto gt = getdist(p[at]);
           gt.first++;
           ops.push_back(make_tuple(gt.second, at, at));
           rdist[at].first = gt.first; rdist[at].second = gt.second;
       }
    }
    return rdist[at];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("ina.txt", "r", stdin);
//    freopen("outa.txt", "w", stdout);
    while (cin >> n) {
        glist.clear();
        glist.resize(n);
        diam.assign(n, false);
        ops.clear();
        rdist.assign(n, ii(-1, -1));
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            glist[u - 1].push_back(v - 1);
            glist[v - 1].push_back(u - 1);
        }
        p.assign(n, -1);
        bfs(0);
        root = farthest;
        p.assign(n, -1);
        bfs(farthest);
        bottom = farthest;
        ll ans = (ll)(dist[farthest]) * (ll)(dist[farthest] + 1) / 2;
        while (farthest != -1) {
            diam[farthest] = true;
//            ops.push_back(make_tuple(root, farthest, farthest));
            farthest = p[farthest];
        }
        for (int i = 0; i < n; i++) {
            if (!diam[i]) {
                auto gt = getdist(i);
                ans += gt.first;
            }
        }
        reverse(ops.begin(), ops.end());
        farthest = bottom;
        while (farthest != -1) {
//            diam[farthest] = true;
            ops.push_back(make_tuple(root, farthest, farthest));
            farthest = p[farthest];
        }
        ops.pop_back(); //For root
        cout << ans << "\n";
        for (int i = 0; i < ops.size(); i++) {
            cout << (get<0> (ops[i])) + 1 << " " << (get<1> (ops[i])) + 1 << " " << (get<2> (ops[i])) + 1 << "\n";
        }
    }
    return 0;
}
