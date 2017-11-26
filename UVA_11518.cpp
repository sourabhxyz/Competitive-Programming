#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > glist;
vector<int> dist;
int cnt;

void bfs(int u)
{
    cnt++;
    dist[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i];
            if(dist[to] == 100000)
            {
                dist[to] = 1;
                q.push(to);
                cnt++;
            }
        }
    }
}

int main()
{
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        dist.assign(n, 100000);
        glist.clear();
        glist.resize(n);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            glist[u].push_back(v);
        }
        cnt = 0;
        for(int i = 0; i < l; i++)
        {
            int z;
            cin >> z;
            if(dist[z - 1] == 100000) bfs(z - 1);
        }
        cout << cnt << "\n";
    }
    return 0;
}
