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
        return wt < other.wt;
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
        int n, m, a;
        cin >> n >> m >> a;
        UFDS uf(n);
        el.clear();
        for(int i = 0; i < m; i++)
        {
            int u, v, wt;
            cin >> u >> v >> wt;
            u--; v--;
            el.push_back(edge(u, v, wt));
        }
        sort(el.begin(), el.end());
        //int tnumSets = uf.numSets;
        int cost = 0, airp = 0;
        for(int i = 0; i < el.size() && uf.numSets > 1; i++)
        {
            int wt = el[i].wt;
            int u = el[i].u, v = el[i].v;
            if(!uf.isSameSet(u, v))
            {
                uf.unionset(u, v);
                if(a > wt)
                {
                    cost += wt;
                } else
                {
                    cost += a;
                    airp++;
                }
            }
        }
        if(uf.numSets > 0)
        {
            airp += uf.numSets;
            cost += uf.numSets * a;
        }
        cout << "Case #" << tc << ": " << cost << " " << airp << "\n";
    }
    return 0;
}
