#include<bits/stdc++.h>

using namespace std;

#define INF 100000

vector<string> data;
vector<vector<int> > glist;
map<string, int> mapping;
vector<int> p;

int diff(int i, int j) {
    int nd = 0;
    if (data[i].size() == data[j].size()) {
        for (int k = 0; k < data[i].size(); k++) {
            if (data[i][k] != data[j][k]) nd++;
        }
    }
    return nd;
}

void getPath(int u, int start)
{
    if(start != u) {
        getPath(p[u], start);
    }
    cout << data[u] << "\n";
}

int bfs(int start, int end)
{
    queue<int> q;
    q.push(start);
    vector<int> dist(data.size(), INF);
    dist[start] = 0;
    p.assign(data.size(), -1);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(u == end) break;
        for(int i = 0; i < glist[u].size(); i++)
        {
            int to = glist[u][i];
            if(dist[to] == INF)
            {
                p[to] = u;
                dist[to] = dist[u] + 1;
                q.push(to);
            }
        }
    }
    if(dist[end] != INF){
        getPath(end, start);
    } else
    {
        cout << "No solution.\n";
    }
}

int main()
{
   // freopen("ina.txt", "r", stdin);
   // freopen("outa.txt", "w", stdout);
    glist.clear();
    data.clear();
    string s;
    while(getline(cin, s) && s != "")
    {
        data.push_back(s);
        mapping[s] = data.size() - 1;
    }
    glist.resize(data.size());
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = i + 1; j < data.size(); j++)
        {
            if(diff(i, j) == 1)
            {
                glist[i].push_back(j);
                glist[j].push_back(i);
            }
        }
    }
    string a, b;
    bool first = true;
    while(cin >> a >> b)
    {
        if(!first)
            cout << "\n";
        else
            first = false;
        bfs(mapping[a] , mapping[b]);
    }

    return 0;
}
