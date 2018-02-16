#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string, int> msi;
typedef map<int,pair<int,int> > miii;
typedef complex<double> point;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
#define X real()
#define Y imag()
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
int m, n, q;
int price[1000];
vii adjList[1000];
// mincost to reach first with second in the tank
int cost[1000][101];
// iii: (cost, (position, fueltank))
priority_queue<iii, viii, greater<iii> > pq;

void query(int c, int s, int e)
{
    while(!pq.empty())
    {
        pq.pop();
    }
    pq.push(iii(0, ii(s, 0)));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            cost[i][j] = 1000000;
        }
    }
    cost[s][0] = 0;
    while(!pq.empty())
    {
        iii f = pq.top(); pq.pop();
        int totalprice = f.first;
        int pos = f.second.first;
        int fuel = f.second.second;
        if(pos == e)
        {
            printf("%d\n", totalprice);
            return;
        }
        if(cost[pos][fuel] == totalprice)
        {
            if(fuel > 0)
            {
                for(int v = 0; v < (int)adjList[pos].size(); v++)
                {
                    ii u = adjList[pos][v];
                    if(fuel-u.second >= 0 && totalprice < cost[u.first][fuel-u.second])
                    {
                        cost[u.first][fuel-u.second] = totalprice;
                        pq.push(iii(totalprice, ii(u.first, fuel-u.second)));
                    }
                }
            }
            if(fuel < c)
            {
                if(totalprice + price[pos] < cost[pos][fuel+1])
                {
                    cost[pos][fuel+1] = totalprice + price[pos];
                    pq.push(iii(totalprice + price[pos], ii(pos, fuel+1)));
                }
            }
        }
    }
    printf("impossible\n");
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &price[i]);
    }
    for(int i = 0; i < m; i++)
    {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        adjList[u].push_back(ii(v, d));
        adjList[v].push_back(ii(u, d));
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int c, s, e;
        scanf("%d %d %d", &c, &s, &e);
        query(c, s, e);
    }
    return 0;
}
