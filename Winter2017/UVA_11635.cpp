/* Toughest problem of the day, key concept is:
"The problem can be simplified by first computing the minimum travel times between the hotels. That means you compute from each hotel, the minimum time it takes via the roads to reach every other hotel.

Then, compute the shortest distance from city 1 to every hotel, similarly for city n.

Using the new distances, form a new graph using the shortest path between hotels and the 2 other cities. If the path length is >600, then ignore it (that means do not put it in the new graph). Then use Dijkstra with each edge having a weight of 1. This will give you the minimum number of hotels needed to reach the destination + 1. If there is no path in the new graph, then it is impossible.

The algorithm would take O((k+2)m log n + m log (k+2)) = O(km log n)"
Credits for this info: https://stackoverflow.com/questions/39273898/shortest-path-uri-online-judge-1640
Rest of the code just follows this idea */

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define INF 100000000
int n, h, m;
vector<int> hotels;
vector<vector<ii > > glist;
vector<int> dist;
vector<vector<ii > > nglist;

void dijkstra(int source)
{
    dist.assign(n, INF);
    dist[source] = 0;
    priority_queue<ii, vector<ii >, greater<ii > > pq;
    pq.push(ii(0, source));
    while(!pq.empty())
    {
        int at = pq.top().second;
        int di = pq.top().first;
        pq.pop();
        if(di == dist[at]) {
            for (int i = 0; i < glist[at].size(); i++) {
                int to = glist[at][i].first;
                int w = glist[at][i].second;
                if(dist[to] > dist[at] + w)
                {
                    dist[to] = dist[at] + w;
                    pq.push(ii(dist[to], to));
                }
            }
        }
    }
}

int dijkstra2()
{
    vector<int> ndist(n, INF);
    ndist[0] = 0;
    priority_queue<ii, vector<ii >, greater<ii > > pq;
    pq.push(ii(0, 0));
    while(!pq.empty())
    {
        int at = pq.top().second;
        int di = pq.top().first;
        pq.pop();
        if(di == ndist[at]) {
            for (int i = 0; i < nglist[at].size(); i++) {
                int to = nglist[at][i].first;
                int w = nglist[at][i].second;
                if(ndist[to] > ndist[at] + w)
                {
                    ndist[to] = ndist[at] + w;
                    pq.push(ii(ndist[to], to));
                }
            }
        }
    }
    return (ndist[n - 1] - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    while(cin >> n && n)
    {
        glist.clear();
        glist.resize(n);
        hotels.clear();
        cin >> h;
        for(int i = 0; i < h; i++)
        {
            int temp;
            cin >> temp;
            hotels.push_back(temp - 1);
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            glist[u - 1].push_back(ii(v - 1, w));
            glist[v - 1].push_back(ii(u - 1, w));
        }
        nglist.clear();
        nglist.resize(n);
        dijkstra(0);
        if(dist[n - 1] <= 600)
        {
            cout << "0\n";
        } else {
            for (int i = 0; i < h; i++) {
                dijkstra(hotels[i]);
                for (int j = i + 1; j < h; j++) {
                    if (dist[hotels[j]] <= 600) {
                        nglist[hotels[i]].push_back(ii(hotels[j], 1));
                        nglist[hotels[j]].push_back(ii(hotels[i], 1));
                    }
                }
            }
            dijkstra(0);
            for (int i = 0; i < h; i++) {
                if (dist[hotels[i]] <= 600) {
                    nglist[0].push_back(ii(hotels[i], 1));
                    nglist[hotels[i]].push_back(ii(0, 1));
                }
            }
            dijkstra(n - 1);
            for (int i = 0; i < h; i++) {
                if (dist[hotels[i]] <= 600) {
                    nglist[n - 1].push_back(ii(hotels[i], 1));
                    nglist[hotels[i]].push_back(ii(n - 1, 1));
                }
            }
            int hcnt = dijkstra2();
            if (hcnt == INF - 1) cout << "-1\n";
            else
                cout << hcnt << "\n";
        }
    }
    return 0;
}
