//This is my incorrect attempt, working code is here: https://github.com/sourabh2311/Competitive-Programming/blob/1e1e9c1aadf78b1db5d9add73cdc142aa32ee478/UVA_11635.cpp
#include<bits/stdc++.h>

using namespace std;

#define INF 100000000
#define margin (10 * 60)
typedef pair<int, int> ii;

int n, h, m;
int hotel[205];
vector<int> dist;
vector<vector<ii > > g;
vector<int> p;
int hcnt;
int graph[10005][10005];

struct info{
    int at;
    int totaltime;
    int timetill;
    info() {}
    info(int at_, int totaltime_, int timetill_){
        at = at_;
        totaltime = totaltime_;
        timetill = timetill_;
    }
    bool operator < (const info &other) const{
        return totaltime > other.totaltime;
    }
};

void dijkstra()
{
    dist.assign(n, INF);
    priority_queue<info> pq;
    pq.push(info(0, 0, 0));
    dist[0] = 0;
    p.clear();
    p.resize(n);
    while(!pq.empty())
    {
        info temp = pq.top(); pq.pop();
        int at = temp.at; int totaltime = temp.totaltime; int timetill = temp.timetill;
        if(totaltime == dist[at]) {
            for (int i = 0; i < g[at].size(); i++)
            {
                int to = g[at][i].first;
                int w = g[at][i].second;
                if(timetill + w <= margin)
                {
                    if(dist[to] > totaltime + w)
                    {
                        dist[to] = totaltime + w;
                        pq.push(info(to, dist[to], timetill + w));
                        p[to] = at;
                    }
                }
                if(hotel[at])
                {
                    if(dist[to] > totaltime + (24*60 - timetill) + w)
                    {
                        dist[to] = totaltime + w + (24*60 - timetill);
                        pq.push(info(to, dist[to], w));
                        p[to] = at;
                    }
                }
            }
        }
    }
}

void ghc(int u)
{
    if(u == 0) return;
    else
    {
        if(dist[u] > dist[p[u]] + graph[u][p[u]])
        {
            hcnt++;
        }
        ghc(p[u]);
    }
}

int main()
{
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                graph[i][j] = graph[j][i] = 0;
            }
            graph[i][i] = 0;
        }
        hcnt = 0;
        cin >> h;
        for(int i = 0; i < n; i++) hotel[i] = false;
        g.clear();
        g.resize(n);
        for(int i = 0; i < h; i++)
        {
            int temp;
            cin >> temp;
            hotel[temp - 1] = true;
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u - 1].push_back(ii(v - 1, w));
            g[v - 1].push_back(ii(u - 1, w));
            graph[u - 1][v - 1] = graph[v - 1][u - 1] = w;
        }
        dijkstra();
        if(dist[n - 1] == INF) cout << "-1\n";
        else
        {
            ghc(n - 1);
            cout << hcnt << "\n";
        }
    }
    return 0;
}
