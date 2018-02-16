#include<bits/stdc++.h>

using namespace std;

#define INF 100000

vector<string> data;
vector<vector<int> > glist;
map<string, int> mapping;

int diff(int i, int j) {
    int nd = 0;
    if (data[i].size() == data[j].size()) {
        for (int k = 0; k < data[i].size(); k++) {
            if (data[i][k] != data[j][k]) nd++;
        }
    }
    return nd;
}

int bfs(int start, int end)
{
    queue<int> q;
    q.push(start);
    vector<int> dist(data.size(), INF);
    dist[start] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(u == end) return dist[end];
        for(int i = 0; i < glist[u].size(); i++)
        {
            int to = glist[u][i];
            if(dist[to] == INF)
            {
                dist[to] = dist[u] + 1;
                q.push(to);
            }
        }
    }
    return dist[end];
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        glist.clear();
        data.clear();
        string s;
        while(cin >> s && s != "*")
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
        cin.ignore();
        string line;
        while(getline(cin, line) && line != "")
        {
            string a, b;
            stringstream ss;
            ss << line;
            ss >> a >> b;
            cout << a << " " << b << " " << bfs(mapping[a] , mapping[b]) << "\n";
        }
        if(n > 0) cout << "\n";
    }
    return 0;
}
