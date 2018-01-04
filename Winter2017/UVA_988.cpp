#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
vector<vector<int> > glist;
vector<int> ts;
vector<bool> visited;

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
    int n;
    bool first = true;
    while(cin >> n) {
        if(first) first = false;
        else cout << "\n";
        vector<long long int> path;
        path.resize(n);
        path[0] = 1;
        glist.clear();
        glist.resize(n);
        vector<int> dl;

        for(int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            if(l == 0)
            {
                dl.push_back(i);
            }
            for(int j = 0; j < l; j++)
            {
                int temp;
                cin >> temp;
                glist[i].push_back(temp);
            }
        }
        ts.clear();
        visited.assign(n, false);
        dfs(0);
        reverse(ts.begin(), ts.end());
        for(int i = 0; i < ts.size(); i++)
        {
            int at = ts[i];
            for(int j = 0; j < glist[at].size(); j++)
            {
                int to = glist[at][j];
                path[to] += path[at];
            }
        }
        int ans = 0;
        for(int i = 0; i < dl.size(); i++)
        {
            int to = dl[i];
            ans += path[to];
        }
        cout << ans << '\n';
    }
    return 0;
}
