#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000

vector<vector<int> > res;
int mf, f, s, t; // global variables
vi p; // p stores the BFS spanning tree from s
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f; } }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    int nt;
    cin >> nt;
    for(int tc = 1; tc <= nt; tc++) {
        map<int, map<int, string> > mp;
        cout << "Case #" << tc << ":\n";
        int n;
        cin >> n;
        s = 0; t = n + n + 1;
        res.assign(n + 2 + n, vector<int>(n + n + 2, 0));
        vector<vector<int> > glist;
        glist.resize(n + n + 2);

        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for(int j = 0; j < k; j++) {
                string name;
                cin >> name;
                char first = name[0];
                first = tolower(first);
                if(first - 97 + 1 > n) continue;
                glist[first - 97 + 1].push_back(i + 1 + n);
                glist[i + 1 + n].push_back(first - 97 + 1);
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                name[0] = toupper(name[0]);
                res[first - 97 + 1][i + 1 + n] = 1;
                mp[first - 97 + 1][i + 1 + n] = name;
            }
        }
        for(int i = 0; i < n; i++) {
            glist[0].push_back(i + 1);
            glist[i + 1].push_back(0);
            res[0][i + 1] = 1;
            glist[i + 1 + n].push_back(t);
            glist[t].push_back(i + 1 + n);
            res[i + 1 + n][t] = 1;
        }
        mf = 0; // mf stands for max_flow
        while (1) { // O(VE^2) (actually O(V^3 E) Edmonds Karp’s algorithm
            f = 0;
// run BFS, compare with the original BFS shown in Section 4.2.2
            vi dist(n + n + 2, inf); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(n + n + 2, -1); // record the BFS spanning tree, from s to t!
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break; // immediately stop BFS if we already reach sink t
                for (auto v : glist[u]) // note: this part is slow
                    if (res[u][v] > 0 && dist[v] == inf)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u; // 3 lines in 1!
            }
            augment(t, inf); // find the min edge weight ‘f’ in this path, if any
            if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
            mf += f; // we can still send a flow, increase the max flow!
        }
        for(int i = 1; i <= n; i++) {
            for(auto to : glist[i]) {
                if(res[i][to] == 0) {
                    cout << mp[i][to] << "\n";
                }
            }
        }
        //cout << mf << "\n";
    }
    return 0;

}
