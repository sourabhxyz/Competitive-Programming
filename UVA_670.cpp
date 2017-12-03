#include<bits/stdc++.h>

using namespace std;

#define INF 100000000
#define EPS 1e-8
int n, m, s, t, f;
const int mv = 205;
int res[mv][mv];
vector<int> p;

struct point{
    int x, y;
    point() {}
    point(int x_, int y_) {
        x = x_;
        y = y_;
    }
    bool operator < (const point &other) const {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

vector<point> bob, ip;
map<point, int> mp;

double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}


void augment(int at, int minedge)
{
    if(at == s) {
        f = minedge; return;
    }
    else if(p[at] != -1)
    {
        augment(p[at], min(minedge, res[p[at]][at]));
        res[p[at]][at] -= f;
        res[at][p[at]] += f;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l;
    cin >> l;
    while(l--)
    {
        cin >> n >> m;
        for(int i = 0; i < mv; i++)
        {
            for(int j = 0; j < mv; j++)
            {
                res[i][j] = 0;
            }
        }
        mp.clear();
        bob.clear();
        bob.resize(n);
        ip.clear();
        ip.resize(m);
        int vb = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> bob[i].x >> bob[i].y;
            mp[bob[i]] = vb++;
        }
        int vip = vb;
        for(int i = 0; i < m; i++)
        {
            cin >> ip[i].x >> ip[i].y;
            mp[ip[i]] = vip++;
        }
        s = vip;
        t = s + 1;
        vector<vector<int> > neig;
        neig.resize(vb);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n - 1; j++)
            {
                int k = j + 1;
                if(dist(bob[j], ip[i]) + dist(bob[k], ip[i]) < 2 * dist(bob[j], bob[k]) + EPS) {
                    res[mp[bob[j]]][mp[ip[i]]] = 1;
                    neig[mp[bob[j]]].push_back(mp[ip[i]]);
                }
            }
        }
        for(int i = 0; i < vb; i++)
        {
            res[s][i] = 1;
        }
        for(int i = vb; i < vip; i++)
        {
            res[i][t] = 1;
        }
        int mf = 0;
        while(true)
        {
            f = 0;
            p.assign(t + 1, -1);
            queue<int> q;
            q.push(s);
            vector<bool> visited(t + 1, false);
            visited[s] = true;
            while(!q.empty())
            {
                int at = q.front(); q.pop();
                if(at == t) break;
                for(int i = 0; i <= t; i++)
                {
                    if(!visited[i] && res[at][i] > 0)
                    {
                        q.push(i);
                        visited[i] = true;
                        p[i] = at;
                    }
                }
            }
            augment(t, INF);
            if(f == 0) break;
            mf += f;
        }
        cout << mf + n << '\n';
        for(int i = 0; i < vb; i++)
        {
            cout << bob[i].x << " " << bob[i].y;
            for(int j = 0; j < neig[i].size(); j++)
            {
                int to = neig[i][j];
                if(res[i][to] == 0)
                {
                    cout << " " << ip[to - vb].x << " " << ip[to - vb].y;
                    break;
                }
            }
            if(i != vb - 1) cout << " ";
        }
        cout << '\n';
        if(l > 0) cout << "\n";
    }
}
