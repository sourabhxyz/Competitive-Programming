#include<bits/stdc++.h>

using namespace std;

vector<vector<int > > glist;
int N;

struct node{
    int vertex, dependencies;
    node() {}
    node(int vertex_, int dependencies_)
    {
        vertex = vertex_;
        dependencies = dependencies_;
    }
    bool operator < (const node &other) const
    {
        if(dependencies != other.dependencies) return dependencies < other.dependencies;
        else return vertex > other.vertex;
    }
};

vector<node> ans;

int bfs(int u)
{
    vector<int> dist(N, 10000);
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    int cnt = 0;
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i];
            if(dist[to] == 10000)
            {
                cnt++;
                dist[to] = dist[at] + 1;
                q.push(to);
            }
        }
    }
    return cnt;
}

int main()
{
    while(cin >> N && N != 0)
    {
        ans.clear();
        glist.clear();
        glist.resize(N);
        for(int i = 0; i < N; i++)
        {
            int T;
            cin >> T;
            for(int j = 0; j < T; j++)
            {
                int v;
                cin >> v;
                glist[i].push_back(v - 1);
            }
        }
        for(int i = 0; i < N; i++)
        {
            ans.push_back(node(i, bfs(i)));
        }
        sort(ans.begin(), ans.end());
        cout << ans[ans.size() - 1].vertex + 1 << "\n";
    }
    return 0;
}
