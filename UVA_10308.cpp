#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int, int> ii;
vector<vector<ii > > glist;
int V;

ii bfs(int source)
{
    vector<bool> visited(V, false);
    visited[source] = true;
    vector<int> dist(V, INF);
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    ii farthest;
    farthest.second = INT_MIN;
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i].first;
            int w = glist[at][i].second;
            if(!visited[to])
            {
                visited[to] = true;
                dist[to] = dist[at] + w;
                if(farthest.second < dist[to])
                {
                    farthest.second = dist[to];
                    farthest.first = to;
                }
                q.push(to);
            }
        }
    }
    return farthest;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string line;
    while(getline(cin, line))
    {
        glist.clear();
        glist.resize(10005);
        V = 0;
        int a, b, w;
        stringstream ss;
        ss << line;
        ss >> a >> b >> w;
        V = max(V, max(a, b));
        glist[a - 1].push_back(ii(b - 1, w));
        glist[b - 1].push_back(ii(a - 1, w));
        while(getline(cin, line) && line != "")
        {
            stringstream s2;
            s2 << line;
            s2 >> a >> b >> w;
            V = max(V, max(a, b));
            glist[a - 1].push_back(ii(b - 1, w));
            glist[b - 1].push_back(ii(a - 1, w));
        }
        ii x = bfs(0);
        ii y = bfs(x.first);
        cout << y.second << "\n";
    }
    return 0;
}
