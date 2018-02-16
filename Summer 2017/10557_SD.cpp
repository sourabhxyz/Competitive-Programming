#include<bits/stdc++.h>

using namespace std;

#define INF 100000000

int n;
vector<vector<int> > glist;
vector<int> roome;

bool bfs(int from, int to)
{
    queue<int> q;
    q.push(from);
    vector<int> dist(n, INF);
    dist[from] = 0;
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to_ = glist[at][i];
            if(dist[to_] == INF)
            {
                dist[to_] = dist[at] + 1;
                q.push(to_);
            }
        }
    }
    if(dist[to] != INF)
    {
        return true;
    }
    return false;
}

bool bellmanford()
{
    vector<int> dist(n, INF);
    dist[0] = -100;
    for(int i = 0; i < n - 1; i++)
    {
        for(int u = 0; u < n; u++)
        {
            for(int j = 0; j < glist[u].size(); j++)
            {
                int to = glist[u][j];
                if(dist[u] + roome[to] < 0 && dist[to] > dist[u] + roome[to])
                {
                    dist[to] = dist[u] + roome[to];
                }
            }
        }
    }
    if(dist[n - 1] < 0)
    {
        return true;
    }
    for(int u = 0; u < n; u++)
    {
        for(int j = 0; j < glist[u].size(); j++)
        {
            int to = glist[u][j];
            if(dist[u] + roome[to] < 0 && dist[to] > dist[u] + roome[to])
            {
                if(bfs(0, u) && bfs(to, n - 1))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n && n != -1)
    {
        glist.clear();
        roome.clear();
        glist.resize(n);
        roome.resize(n);
        for(int i = 0; i < n; i++)
        {
            int e;
            cin >> e;
            roome[i] = -1 * e;
            int nei;
            cin >> nei;
            for(int j = 0; j < nei; j++)
            {
                int no;
                cin >> no;
                glist[i].push_back(no - 1);
            }
        }
        bellmanford() ? cout << "winnable\n" : cout << "hopeless\n";
    }
    return 0;
}
