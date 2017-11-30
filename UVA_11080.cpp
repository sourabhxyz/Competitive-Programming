#include<bits/stdc++.h>

using namespace std;

#define INF 100000000
typedef pair<int, int> ii;
int v, e;
vector<vector<int> > g;
vector<int> dist;
vector<bool> tmark;

int bfs(int source, int mark)
{
    int cnt = 0;
    queue<pair<int, int > > q;
    dist[source] = 0;
    q.push(ii(source, mark));
    while(!q.empty())
    {
        int at = q.front().first;
        int mk = q.front().second;
        q.pop();
        if(mk) {
            tmark[at] = true;
            cnt++;
        }
        for(int i = 0; i < g[at].size(); i++)
        {
            int to = g[at][i];
            if(dist[to] == INF)
            {
                dist[to] = dist[at] + 1;
                q.push(ii(to, 1 - mk));
            }
        }
    }
    return cnt;
}

void revbfs(int source, int mark)
{
    queue<pair<int, int > > q;
    dist[source] = INF;
    q.push(ii(source, mark));
    while(!q.empty())
    {
        int at = q.front().first;
        int mk = q.front().second;
        if(mk) tmark[at] = false;
        q.pop();
        for(int i = 0; i < g[at].size(); i++)
        {
            int to = g[at][i];
            if(dist[to] != INF)
            {
                dist[to] = INF;
                q.push(ii(to, 1 - mk));
            }
        }
    }
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
        cin >> v >> e;
        g.clear();
        g.resize(v);
        for(int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        tmark.clear();
        tmark.assign(v, false);
        dist.assign(v, INF);
        for(int i = 0; i < v; i++) {
            if (dist[i] == INF) {
                int t1 = bfs(i, 0);
                revbfs(i, 0);
                int t2 = bfs(i, 1);
                if(t1 <= t2)
                {
                    revbfs(i, 1);
                    bfs(i, 0);
                    ans += t1;
                } else
                {
                    ans += t2;
                }
            }
        }
        for(int i = 0; i < v; i++)
        {
            if(g[i].empty())
            {
                tmark[i] = true;
                ans++;
            }
        }
        bool found = true;
        for(int i = 0; i < v && found; i++)
        {
            for(int j = 0; j < g[i].size() && found; j++)
            {
                int to = g[i][j];
                if(tmark[i] || tmark[to])
                {
                    continue;
                }
                else
                {
                    found = false;
                }
            }
        }
        if(found) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}
