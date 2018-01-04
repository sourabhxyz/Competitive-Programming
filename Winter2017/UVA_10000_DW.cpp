#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
int n, s;
vector<vector<pair<int, int> > > glist;
vector<bool> visited;
vector<int> ts;

void dfs(int u)
{
    visited[u] = true;
    for(int i = 0; i < glist[u].size(); i++)
    {
        int to = glist[u][i].first;
        if(!visited[to])
        {
            dfs(to);
        }
    }
    ts.push_back(u);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t = 1;
    while(cin >> n && n)
    {
        ts.clear();
        visited.assign(n + 5, false);
        glist.clear();
        glist.resize(n + 5);
        cin >> s;
        s--;
        int p, q;
        while(cin >> p >> q && (p || q))
        {
            glist[p - 1].push_back(make_pair(q - 1, -1));
        }
        dfs(s);
        reverse(ts.begin(), ts.end());
        vector<int> dist(n, INF);
        dist[s] = 0;
        int min_ = 0;
        int end = s;
        for(int i = 0; i < ts.size(); i++)
        {
            int at = ts[i];
            for(int i = 0; i < glist[at].size(); i++)
            {
                int to = glist[at][i].first;
                int w = glist[at][i].second;
                if(dist[to] > dist[at] + w)
                {
                    dist[to] = dist[at] + w;
                    if(min_ > dist[to])
                    {
                        min_ = dist[to];
                        end = to;
                    }
                }
            }
        }
        cout << "Case " << t++ << ": The longest path from " << s + 1 << " has length " << abs(min_) <<", finishing at " << end + 1 << ".\n\n";
    }
    return 0;
}
