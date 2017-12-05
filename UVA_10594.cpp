/* Toughest problem of the day, it took me maybe more than 4 hours. I dont think this topic is nicely explained in the Halims book */

#include<bits/stdc++.h>

using namespace std;

#define INF 10000000000000000
typedef pair<int, int> ii;
int n, m;
long long int fixedcap, totransfer, f;
vector<int> p;
#define EPS 1e-7

struct link{
    long long int cap;
    long long int cost;
    link() {}
    link(int cp, int ct) {
        cap = cp;
        cost = ct;
    }
};

vector<vector<link> > mat;
vector<vector<int> > glist;
vector<vector<long long int> > flow;

void augment(int at, long long int minedge)
{
    if(at == 0) {
        f = minedge;
        return;
    }
    else if(p[at] != -1) {
        augment(p[at], min(mat[p[at]][at].cap - flow[p[at]][at], minedge));
        flow[p[at]][at] += f;
        flow[at][p[at]] -= f;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("ina.txt", "r", stdin);
   // freopen("outa.txt", "w", stdout);
    while(cin >> n >> m)
    {
        mat.clear();
        glist.clear();
        glist.resize(n + 1);
        mat.assign(n + 1, vector<link>(n + 1, link(0, 0)));
        flow.assign(n + 1, vector<long long int>(n + 1, 0));
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            glist[u].push_back(v);
            glist[v].push_back(u);
            mat[u][v].cost = mat[v][u].cost = w;
        }
        cin >> totransfer >> fixedcap;
        mat[0][1] = link(totransfer, 0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < glist[i].size(); j++)
            {
                int to = glist[i][j];
                mat[i][to].cap = fixedcap;
            }
        }
        glist[0].push_back(1);
        long long int mf = 0, mincost = 0;
        while(true) {
            vector<long long int> dist(n + 1, INF);
            dist[0] = 0;
            p.assign(n + 1, -1);
            for(int i = 0; i < n; i++)
            {
                for(int u = 0; u <= n; u++)
                {
                    for(auto to : glist[u])
                    {
                        if(flow[to][u] > 0 && dist[u] - mat[to][u].cost < dist[to])
                        {
                            dist[to] = dist[u] - mat[to][u].cost;
                            p[to] = u;
                        }
                        else if(mat[u][to].cap - flow[u][to] > 0 && dist[u] + mat[u][to].cost < dist[to]) {
                            dist[to] = dist[u] + mat[u][to].cost;
                            p[to] = u;
                        }
                    }
                }
            }
            if(dist[n] == INF) break;
            augment(n, INF);
            if(f == 0) break;
            mf += f;
            mincost += dist[n] * f;
        }

        if(mf == totransfer)
            cout << mincost << "\n";
        else cout << "Impossible.\n";
    }
    return 0;
}
