#include<bits/stdc++.h>

using namespace std;

int graph[1005][1005];
int dfs_low[1005], dfs_num[1005], dfsNC, n, p[1005];

void fb(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNC++;
    for(int i = 0; i < n; i++)
    {
        if(!graph[u][i]) continue;
        if(dfs_num[i] == -1)
        {
            p[i] = u;
            fb(i);
            if(dfs_low[i] <= dfs_num[u])
            {
                graph[i][u] = 0;
            }
            dfs_low[u] = min(dfs_low[i], dfs_low[u]);
        }
        else if(i != p[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[i]);
            graph[i][u] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, k = 1;
    while(cin >> n >> m && (n || m))
    {
        dfsNC = 0;
        for(int i = 0; i < n; i++) {
            dfs_low[i] = dfs_num[i] = p[i] = -1;
            for (int j = 0; j < n; j++) graph[i][j] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1;
        }
        cout << k++ << "\n\n";
        fb(0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j])
                {
                    cout << i + 1 << " " << j + 1 << "\n";
                }
            }
        }
        cout << "#\n";
    }
    return 0;
}
