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
map<string, int> data;

int main()
{
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, c;
    int k;
    while(cin >> s >> c && (s || c))
    {
        k = 0;
        data.clear();
        UFDS uf(s);
        el.clear();
        for(int i = 0; i < s; i++)
        {
            string s;
            cin >> s;
            data[s] = k++;
        }
        for(int i = 0; i < c; i++)
        {
            int wt;
            string a, b;
            cin >> a >> b >> wt;
            el.push_back(edge(data[a], data[b], wt));
        }
        sort(el.begin(), el.end());
        int cost = 0;
        for(int i = 0; i < el.size(); i++)
        {
            int wt = el[i].wt;
            int u = el[i].u, v = el[i].v;
            if(!uf.isSameSet(u, v))
            {
                uf.unionset(u, v);
                cost += wt;
            }
        }
        string temp;
        cin >> temp;
        if(uf.numSets > 1) cout << "Impossible\n";
        else cout << cost << "\n";
    }
    return 0;
}
