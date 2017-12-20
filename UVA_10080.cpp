#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000

struct point{
    double x, y;
    point() {}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
};

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

vector<vector<int> > glist;
vector<vector<int> > res;
int mf, f, source, t; // global variables
vi p; // p stores the BFS spanning tree from s
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == source) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    int n, m, s, vel;
    while(cin >> n >> m >> s >> vel) {
        vector<point> gropher;
        gropher.resize(n);
        res.assign(n + m + 2, vector<int>(n + m + 2, 0));
        for(int i = 0; i < n; i++) {
            cin >> gropher[i].x >> gropher[i].y;
        }
        vector<point> holes;
        holes.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> holes[i].x >> holes[i].y;
        }
        source = 0;
        t = n + m + 1;
        glist.clear();
        glist.resize(n + m + 2);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                double d = dist(gropher[i], holes[j]);
                d /= vel;
                if(d < (double)s + eps) {
                    res[i + 1][n + 1 + j] = 1;
                    glist[i + 1].push_back(n + 1 + j);
                    glist[n + 1 + j].push_back(i + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            res[0][i] = 1;
            glist[0].push_back(i);
            glist[i].push_back(0);
        }
        for(int i = n + 1; i <= n + m; i++) {
            res[i][t] = 1;
            glist[i].push_back(t);
            glist[t].push_back(i);
        }
        mf = 0; // mf stands for max_flow

        while (1) { // O(VE^2) (actually O(V^3 E) Edmonds Karp’s algorithm
            f = 0;
// run BFS, compare with the original BFS shown in Section 4.2.2
            vi dist(n + m + 2, inf); dist[source] = 0; queue<int> q; q.push(source);
            p.assign(n + m + 2, -1); // record the BFS spanning tree, from s to t!
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == t) break; // immediately stop BFS if we already reach sink t
                for (auto v : glist[u]){
                    if(res[u][v] > 0 && dist[v] == inf)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u; // 3 lines in 1!
                }
            }
            augment(t, inf); // find the min edge weight ‘f’ in this path, if any
            if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
            mf += f; // we can still send a flow, increase the max flow!
        }
        cout << n - mf << "\n";
    }
    return 0;

}
