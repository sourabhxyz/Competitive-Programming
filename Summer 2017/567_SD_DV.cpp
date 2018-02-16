#include<bits/stdc++.h>

using namespace std;

vector<vector<int > > glist;

int bfs(int u, int v)
{
    vector<int> dist(21, 10000);
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        if(at == v) return dist[v];
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i];
            if(dist[to] == 10000)
            {
                dist[to] = dist[at] + 1;
                q.push(to);
            }
        }
    }
    return dist[v];
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int tc = 1;
    int x;
    while(cin >> x)
    {
        glist.clear();
        glist.resize(21);
        for(int i = 0; i < x; i++)
        {
            int u;
            cin >> u;
            u--;
            glist[0].push_back(u);
            glist[u].push_back(0);
        }
        for(int i = 1; i <= 18; i++)
        {
            cin >> x;
            for(int j = 0; j < x; j++)
            {
                int u;
                cin >> u;
                u--;
                glist[i].push_back(u);
                glist[u].push_back(i);
            }
        }
        int n;
        cin >> n;
        cout << "Test Set #" << tc++ << "\n";
        for(int i = 0; i < n; i++)
        {			
            int u, v;
            cin >> u >> v;
            u--; v--;
            cout << setw(2) << u + 1 << " to " << setw(2) << v + 1 << ": " << bfs(u, v) << "\n";
        }
        cout << "\n";
    }
    return 0;
}
