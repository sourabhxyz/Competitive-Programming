#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int, int> ii;
vector<vector<int> > glist;
vector<bool> visited;
vector<int> ts;

void dfs(int u)
{
    visited[u] = true;
    for(int i = 0; i < glist[u].size(); i++)
    {
        int to = glist[u][i];
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
    int a, b;
    int k = 1;
    map<int, int> data;
    while(cin >> a >> b && (a + b >= 0))
    {
        if(a + b == 0)
        {
            cout << "Case " << k++ << " is a tree.\n";
            continue;
        }
        if(a == b)
        {
            cout << "Case " << k++ << " is not a tree.\n";
            while(cin >> a >> b && (a + b != 0));
            continue;
        }
        vector<int> cnt(10000, 0);
        vector<bool> mark(10000, false);
        data.clear();
        int v = 0;
        data[a] = v++;
        data[b] = v++;
        mark[data[b]] = true;
        cnt[data[b]]++;
        glist.clear();
        glist.resize(10000);
        glist[data[a]].push_back(data[b]);
        bool old = false;
        while(cin >> a >> b && (a + b != 0))
        {
            if(a == b)
            {
                old = true;
            }
            if(data.find(a) == data.end())
                data[a] = v++;
            if(data.find(b) == data.end())
                data[b] = v++;
            mark[data[b]] = true;
            glist[data[a]].push_back(data[b]);
            cnt[data[b]]++;
        }
        glist.resize(v);
        if(old)
        {
            cout << "Case " << k++ << " is not a tree.\n";
            continue;
        }
        int root = 0;
        int rooti;
        for(int i = 0; i < v; i++)
        {
            if(!glist[i].empty() && !mark[i])
            {
                root++;
                rooti = i;
            }
        }
        if(root == 0 || root > 1)
        {
            cout << "Case " << k++ << " is not a tree.\n";
            continue;
        }
        for(int i = 0; i < v; i++)
        {
            if(cnt[i] > 1)
            {
                old = true;
                break;
            }
        }
        if(old)
        {
            cout << "Case " << k++ << " is not a tree.\n";
            continue;
        }
        vector<int> paths(v, 0);
        paths[rooti] = 1;
        visited.assign(v, false);
        ts.clear();
        dfs(rooti);
        reverse(ts.begin(), ts.end());
        for(int i = 0; i < ts.size(); i++)
        {
            int at = ts[i];
            for(int j = 0; j < glist[at].size(); j++)
            {
                int to = glist[at][j];
                paths[to] += paths[at];
            }
        }
        for(int i = 0; i < v; i++)
        {
            if(paths[i] != 1)
            {
                old = true;
                break;
            }
        }
        if(old)
        {
            cout << "Case " << k++ << " is not a tree.\n";
            continue;
        }
        cout << "Case " << k++ << " is a tree.\n";
    }
    return 0;
}
