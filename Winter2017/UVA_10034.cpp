#include<bits/stdc++.h>

using namespace std;

struct UFDS{
    vector<int> rank, p, size;
    UFDS() {}
    UFDS(int N)
    {
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
        }
    }
};

struct point{
    double x, y;
    point() {}
    point(double x_, double y_)
    {
        x = x_; y = y_;
    }
};

struct edge{
    int u, v;
    double wt;
    edge() {}
    edge(int u_, int v_, double wt_)
    {
        u = u_; v = v_; wt = wt_;
    }
    bool operator < (const edge &other) const{
        return wt < other.wt;
    }
};

vector<edge> el;
vector<point> data;

double dist(int i, int j)
{
    point a = data[i], b = data[j];
    double dist_ = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return dist_;
}

int main()
{
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        data.clear();
        int n;
        cin >> n;
        UFDS uf(n);
      //  glist.clear();
      //  glist.resize(n);
        el.clear();
        for(int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            data.push_back(point(x, y));
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                el.push_back(edge(i, j, dist(i, j)));
                //glist[i].push_back(make_pair(j, dist(i, j)));
                //glist[j].push_back(make_pair(i, dist(i, j)));
            }
        }
        sort(el.begin(), el.end());
        double sum = 0;
        for(int i = 0; i < el.size(); i++)
        {
            int a = el[i].u, b = el[i].v;
            double wt = el[i].wt;
            if(!uf.isSameSet(a, b)) {
                uf.unionset(a, b);
                sum += wt;
            }
        }
        cout << fixed << setprecision(2) << sum << "\n";
        if(t > 0) cout << "\n";
    }
    return 0;
}
