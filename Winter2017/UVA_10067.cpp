#include<bits/stdc++.h>

using namespace std;

vector<int> glist[10000];
int g1, g2, g3, g4, t1, t2, t3, t4;
vector<bool> vis;

int getnum(int th, int h, int t, int o)
{
    return ((th * 1000) + (h * 100) + (t * 10) + o);
}

void drawEdge(int u)
{
    int at = u;
    int o = u % 10;
    u /= 10;
    int t = u % 10;
    u /= 10;
    int h = u % 10;
    u /= 10;
    int th = u;
    if(o == 0) glist[at].push_back(getnum(th, h, t, 9));
    if(o < 9) glist[at].push_back(getnum(th, h, t, o + 1));
    if(o == 9) glist[at].push_back(getnum(th, h, t, 0));
    if(t == 0) glist[at].push_back(getnum(th, h, 9, o));
    if(t == 9) glist[at].push_back(getnum(th, h, 0, o));
    if(h == 0) glist[at].push_back(getnum(th, 9, t, o));
    if(h == 9) glist[at].push_back(getnum(th, 0, t, o));
    if(th == 0) glist[at].push_back(getnum(9, h, t, o));
    if(th == 9) glist[at].push_back(getnum(0, h, t, o));

    if(o > 0) glist[at].push_back(getnum(th, h, t, o - 1));
    if(t < 9) glist[at].push_back(getnum(th, h, t + 1, o));
    if(t > 0) glist[at].push_back(getnum(th, h, t - 1, o));
    if(h < 9) glist[at].push_back(getnum(th, h + 1, t, o));
    if(h > 0) glist[at].push_back(getnum(th, h - 1, t, o));
    if(th < 9) glist[at].push_back(getnum(th + 1, h, t, o));
    if(th > 0) glist[at].push_back(getnum(th - 1, h, t, o));
}

int bfs(int from, int to)
{
    queue<int> q;
    q.push(from);
    vis[from] = true;
    vector<int> dist(10000, -1);
    dist[from] = 0;
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        if(at == to) return dist[to];
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to_ = glist[at][i];
            if(!vis[to_])
            {
                q.push(to_);
                vis[to_] = true;
                dist[to_] = dist[at] + 1;
            }
        }
    }
    return dist[to];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 10000; i++)
    {
        drawEdge(i);
    }
    int n;
    cin >> n;
    while(n--)
    {
        vis.assign(10000, false);
        cin >> g1 >> g2 >> g3 >> g4 >> t1 >> t2 >> t3 >> t4;
        int from = (g1 * 1000) + (g2 * 100) + (g3 * 10) + g4;
        int to = (t1 * 1000) + (t2 * 100) + (t3 * 10) + t4;
        int m;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            vis[getnum(a, b, c, d)] = true;
        }
        int cnt = bfs(from, to);
        if(cnt == 100000) cout << "-1\n";
        else cout << cnt << "\n";

    }

    return 0;
}
