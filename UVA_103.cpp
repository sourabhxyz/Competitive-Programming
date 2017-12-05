#include<bits/stdc++.h>

using namespace std;

#define INF 100000000
vector<vector<int> > glist;
vector<bool> visited;
vector<int> ts, p;

void printpath(int u)
{
    if(p[u] != -1) {
        printpath(p[u]);
        cout << " " << u + 1;
    }
    else
        cout << u + 1;
}

void dfs(int u)
{
    visited[u] = true;
    for(auto to : glist[u])
    {
        if(!visited[to]) {
            dfs(to);
        }
    }
    ts.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("ina.txt", "r", stdin);
   // freopen("outa.txt", "w", stdout);
    int numbox, dim;
    while(cin >> numbox >> dim)
    {
        glist.clear();
        glist.resize(numbox);
        vector<int> boxdims[numbox];
        for(int i = 0; i < numbox; i++)
        {
            for(int j = 0; j < dim; j++)
            {
                int temp;
                cin >> temp;
                boxdims[i].push_back(temp);
            }
            sort(boxdims[i].begin(), boxdims[i].end());
        }
        for(int i = 0; i < numbox; i++)
        {
            for(int j = 0; j < numbox; j++)
            {
                if(i == j) continue;
                int l;
                for(l = 0; l < dim; l++)
                {
                    if(boxdims[i][l] >= boxdims[j][l])
                    {
                        break;
                    }
                }
                if(l == dim) {
                    glist[i].push_back(j);
                }
            }
        }
        visited.clear();
        visited.assign(numbox, false);
        ts.clear();
        for(int i = 0; i < numbox; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        reverse(ts.begin(), ts.end());
        vector<int> dist(numbox, 0);
        //dist[ts[0]] = 0;
        p.clear();
        p.assign(numbox, -1);
        int mn = 0;
        for(auto at : ts)
        {
            for(int to : glist[at]) {
                if(dist[to] < dist[at] + 1)
                {
                    dist[to] = dist[at] + 1;
                    p[to] = at;
                    mn = max(mn, dist[to]);
                }
            }
        }
        cout << abs(mn + 1) << "\n";
        if(mn == 0)
        {
            cout << "1\n";
            continue;
        }
        for(int i = 0; i < numbox; i++)
        {
            if(dist[i] == mn)
            {
                printpath(i);
                break;
            }
        }
        cout << "\n";
    }
    return 0;
}
