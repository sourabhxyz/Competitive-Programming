/* Toughest problem of the day, it took me maybe more than 4 hours. I dont think this topic is nicely explained in the Halims book */

#include<bits/stdc++.h>

using namespace std;

#define INF 10000000000000000
typedef long long int ll;
typedef pair<int, int> ii;
int n, m;
long long int fixedcap, totransfer, f;
vector<ii> p;
#define EPS 1e-7
struct link{
    long long int cap;
    long long int cost;
    long long int flow;
    link() {
        flow = 0;
    }
    link(int cp, int ct) {
        cap = cp;
        cost = ct;
        flow = 0;
    }
};
vector<vector<ii> > glist;
link mat[105][105][2];
void augment(int at, long long int minedge)
{
    if(at == 0) {
        f = minedge;
        return;
    }
    else if(p[at].first != -1) {
        augment(p[at].first, min(mat[p[at].first][at][p[at].second].cap - mat[p[at].first][at][p[at].second].flow, minedge));
        mat[p[at].first][at][p[at].second].flow += f;
        mat[at][p[at].first][p[at].second].flow -= f;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     freopen("ina.txt", "r", stdin);
     freopen("outa.txt", "w", stdout);
    while(cin >> n >> m)
    {
        glist.clear();
        glist.resize(n + 1);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            glist[u].push_back (ii (v, 0));
            glist[v].push_back (ii (u, 1));
            mat[u][v][0].cost = w;
            mat[v][u][0].cost = -w;
            mat[v][u][1].cost = w;
            mat[u][v][1].cost = -w;
        }
        cin >> totransfer >> fixedcap;
        mat[0][1][0] = link(totransfer, 0);
        mat[1][0][0] = link (0, 0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < glist[i].size(); j++)
            {
                auto to = glist[i][j];
                mat[i][to.first][to.second].cap = fixedcap;
                mat[to.first][i][to.second].cap = 0;
            }
        }
        glist[0].push_back(ii(1, 0));
        long long int mf = 0, mincost = 0;
        while(true) {
            vector<long long int> dist(n + 1, INF);
            dist[0] = 0;
            p.assign(n + 1, ii (-1, -1));
            for(int i = 0; i < n; i++)
            {
                for(int u = 0; u <= n; u++)
                {
                    for(auto to : glist[u])
                    {
                        if (mat[to.first][u][to.second].flow > 0 and dist[to.first] + mat[to.first][u][to.second].cost < dist[u]) {
                            dist[u] = dist[to.first] + mat[to.first][u][to.second].cost;
                            p[u].first = to.first;
                            p[u].second = to.second;
                        }
                        if (mat[u][to.first][to.second].cap - mat[u][to.first][to.second].flow > 0 and dist[u] + mat[u][to.first][to.second].cost < dist[to.first]) {
                            dist[to.first] = dist[u] + mat[u][to.first][to.second].cost;
                            p[to.first].first = u;
                            p[to.first].second = to.second;
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
