#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
#define ll long long int
int n, s;
vector<vector<pair<int, ll> > > glist;
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
        vector<ll> dist(n, 0);
        //dist[s] = 0;
        ll min_ = 0;
        int end = s;
        vector<int> endlist;
        for(int i = 0; i < ts.size(); i++)
        {
            int at = ts[i];
            for(auto sp : glist[at])
            {
                int to = sp.first;
                int w = sp.second;
                if(dist[to] > dist[at] + w)
                {
                    dist[to] = dist[at] + w;
                    if(min_ > dist[to]) {
                        endlist.clear();
                        min_ = dist[to];
                    }
                    if(min_ == dist[to]) {
                        endlist.push_back(to);
                    }
                }
            }
        }
        vector<int>:: iterator it;
        it = min_element(endlist.begin(), endlist.end());
        cout << "Case " << t++ << ": The longest path from " << s + 1 << " has length " << abs(min_) <<", finishing at " << *it + 1 << ".\n\n";
    }
    return 0;
}
