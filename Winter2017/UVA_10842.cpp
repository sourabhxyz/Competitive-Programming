#include<bits/stdc++.h>

using namespace std;

struct UFDS{
    int numSets;
    vector<int> rank, p, size;
    UFDS() {}
    UFDS(int N)
    {
        numSets = N;
        rank.assign(N, 0);
        size.assign(N, 1);
        p.clear();
        p.resize(N);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findset(int u)
    {
        return p[u] == u ? u : p[u] = findset(p[u]);
    }
    bool isSameSet(int u, int v)
    {
        return findset(u) == findset(v);
    }
    void unionset(int u, int v)
    {
        if(!isSameSet(u, v)) {
            int x = findset(u), y = findset(v);
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
            } else
            {
                p[x] = y;
                size[y] += size[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
            numSets--;
        }
    }
};

struct edge{
    int u, v;
    int wt;
    edge() {}
    edge(int u_, int v_, int wt_)
    {
        u = u_; v = v_; wt = wt_;
    }
    bool operator < (const edge &other) const{
        return wt > other.wt;
    }
};

vector<edge> el;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int n, m;
        cin >> n >> m;
        int graph[n][n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                graph[i][j] = -1;
            }
        }
        UFDS uf(n);
        el.clear();
        for(int i = 0; i < m; i++)
        {
            int wt;
            int a, b;
            cin >> a >> b >> wt;
            graph[a][b] = max(graph[a][b], wt);
            //el.push_back(edge(a, b, wt));
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] != -1)
                {
                    el.push_back(edge(i, j, graph[i][j]));
                }
            }
        }
        sort(el.begin(), el.end());
        int ans;
        for(int i = 0; i < el.size(); i++)
        {
            int wt = el[i].wt;
            int u = el[i].u, v = el[i].v;
            if(!uf.isSameSet(u, v))
            {
                uf.unionset(u, v);
                ans = wt;
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}
