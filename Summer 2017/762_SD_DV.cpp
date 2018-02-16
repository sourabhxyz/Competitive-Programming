#include<bits/stdc++.h>

using namespace std;

vector<vector<int > > glist;
map<string, int> data;
vector<string> mp;
vector<string> path;
vector<int> p;

void getPath(int u, int start)
{
    if(u == start) {
        path.push_back(mp[u]);
    }
    else
    {
        getPath(p[u], start);
        path.push_back(mp[u]);
    }
}

void bfs(string a, string b)
{
    vector<int> dist(1000, 10000);
    p.assign(1000, -1);
    dist[data[a]] = 0;
    queue<int> q;
    q.push(data[a]);
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i];
            if(dist[to] == 10000)
            {
                p[to] = at;
                dist[to] = dist[at] + 1;
                q.push(to);
            }
        }
    }
    getPath(data[b], data[a]);
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    bool first = true;
    int E;
    while(cin >> E) {
        if(first) first = false;
        else cout << "\n";
        mp.clear();
        glist.clear();
        glist.resize(1000);
        int k = 0;
        data.clear();
        for (int i = 0; i < E; i++) {
            string a, b;
            cin >> a >> b;
            if (data.find(a) == data.end()) {
                data[a] = k++;
                mp.push_back(a);
            }
            if(data.find(b) == data.end())
            {
                data[b] = k++;
                mp.push_back(b);
            }
            glist[data[a]].push_back(data[b]);
            glist[data[b]].push_back(data[a]);
        }
        string a, b;
        cin >> a >> b;
        bfs(a, b);
        if(p[data[b]] != -1)
            for(int i = 0; i < path.size() - 1; i++)
                {
                    cout << path[i] << " " << path[i + 1] << '\n';
                }
        else cout << "No route\n";
    }
    return 0;
}
