#include<bits/stdc++.h>

using namespace std;

#define INF 100000000

int g[1003][1003];
int n, m;

struct info{
    int x, y;
    int dist;
    info() {}
    info(int x_, int y_, int dist_) {x = x_; y = y_; dist = dist_;}
    bool operator < (const info &other) const{
        return dist > other.dist;
    }
};

int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};

bool bound(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    return true;
}

int dijkstra()
{
    priority_queue<info> pq;
    pq.push(info(0, 0, g[0][0]));
    vector<vector<int> > dist(n, vector<int> (m, INF));
    dist[0][0] = g[0][0];
    while(!pq.empty())
    {
        info u = pq.top();
        pq.pop();
        if(u.x == n - 1 && u.y == m - 1) return dist[n - 1][m - 1];
        if(dist[u.x][u.y] == u.dist)
        {
            for(int i = 0; i < 4; i++)
            {
                int nr = u.x + dr[i];
                int nc = u.y + dc[i];
                if(bound(nr, nc) && dist[nr][nc] > dist[u.x][u.y] + g[nr][nc])
                {
                    dist[nr][nc] = dist[u.x][u.y] + g[nr][nc];
                    pq.push(info(nr, nc, dist[nr][nc]));
                }
            }
        }
    }
    return dist[n - 1][m - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> g[i][j];
            }
        }
        cout << dijkstra() << "\n";
    }
    return 0;
}
