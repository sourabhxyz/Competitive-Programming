#include<bits/stdc++.h>

using namespace std;

vector<vector<int > > glist;
map<char, int> data;
vector<char> ts;
bool isThere[100];
bool visited[100];

void dfs(int u)
{
    visited[u] = true;
    for(int i = 0; i < glist[u].size(); i++)
    {
        int now = glist[u][i];
        if(!visited[now])
        {
            dfs(now);
        }
    }
    ts.push_back(65 + u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 28; i++)
    {
        data[65 + i] = i;
    }
    string a;
    cin >> a;
    glist.resize(28);
    memset(isThere, 0, sizeof isThere);
    memset(visited, 0, sizeof visited);
    while(a != "#")
    {
        string prev = a;
        cin >> a;
        for(int i = 0; i < prev.size(); i++)
        {
            isThere[data[prev[i]]] = true;
        }
        if(a == "#") break;
        for(int i = 0; i < prev.size(); i++) {
            if (prev[0] != a[0]) {
                glist[data[prev[0]]].push_back(data[a[0]]);
                break;
            }
            if (prev[i] != a[i]) {
                glist[data[prev[i]]].push_back(data[a[i]]);
                break;
            }
        }
    }
    int start;
    for(int i = 0; i < 100; i++)
    {
        if(isThere[i] && !visited[i])
        {
            dfs(i);
        }

    }
    reverse(ts.begin(), ts.end());
    for(int i = 0; i < ts.size(); i++)
        cout << ts[i];
    cout << "\n";
}
