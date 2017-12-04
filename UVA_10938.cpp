#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
vector<vector<int> > glist;
int n;
vector<vector<int> > dist;

void bfs(int source)
{
    dist[source][source] = 0;
    queue<int> q;
    vector<int> sdist(n, INF);
    sdist[source] = 0;
    q.push(source);
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i];
            if(sdist[to] == INF)
            {
                sdist[to] = sdist[at] + 1;
                q.push(to);
                dist[source][to] = sdist[to];
            }
        }
    }
}

void apsp()
{
    for(int i = 0; i < n; i++)
    {
        bfs(i);
    }
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
        for(int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            glist[a - 1].push_back(b - 1);
            glist[b - 1].push_back(a - 1);
        }
        dist.assign(n, vector<int> (n, INF));
        int l;
        cin >> l;
        apsp();
        for(int i = 0; i < l; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            bool meet = false;
            int where;
            int d = INT_MAX;
            for(int i = 0; i < n; i++)
            {
                if(dist[a][i] == dist[b][i])
                {
                    meet = true;
                    if(d > dist[a][i])
                    {
                        d = dist[a][i];
                        where = i + 1;
                    }
                }
            }
            if(meet)
            {
                cout << "The fleas meet at " << where << ".\n";
                continue;
            }
            cout << "The fleas jump forever between ";
            d = INT_MAX;
            int pa, pb;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < glist[i].size(); j++)
                {
                    int to = glist[i][j];
                    if(dist[a][i] == dist[b][to] && dist[i][to] == 1)
                    {
                        if(d > dist[a][i])
                        {
                            d = dist[a][i];
                            pa = i + 1;
                            pb = to + 1;
                        }
                    }
                }
               
            }
            cout << min(pa, pb) << " and " << max(pa, pb) << ".\n";
        }
    }
    return 0;
}
