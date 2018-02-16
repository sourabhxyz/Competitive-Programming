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

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int E,u,v,k,node,ttl,cnt,cases=0;
    vector<vector<int > > AdjList;
    map<int,int> data;
    map<int,int>::iterator it;
    while(cin>>E&&E)
    {
        AdjList.clear();
        AdjList.resize(30);
        data.clear();
        k=0;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            it=data.find(u);
            if(it==data.end())
            data[u]=k++;
            it=data.find(v);
            if(it==data.end())
            data[v]=k++;
            AdjList[data[u]].push_back(data[v]);
            AdjList[data[v]].push_back(data[u]);
        }
        while(cin>>node>>ttl&&(node||ttl))
        {
            cases++;
            it=data.find(node);
            if(it==data.end())
            {
                cout<<"Case "<<cases<<": ";
                cout<<k;///'-1' since the starting node is also counted as viewed.
                cout<<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<".\n";
                continue;
            }
            if(ttl==0)
            {
                cout<<"Case "<<cases<<": ";
                cout<<k-1;///'-1' since the starting node is also counted as viewed.
                cout<<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<".\n";
                continue;
            }
            cnt=0;
            vi dist(k, INF); dist[data[node]] = 0; // distance from source s to s is 0
            queue<int> q; q.push(data[node]);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    int v = AdjList[u][j];
                    if (dist[v] == INF) {
                        dist[v] = dist[u] + 1;
                        if(dist[v]<=ttl) cnt++;
                        q.push(v);
                    }
                }
            }
            cout<<"Case "<<cases<<": ";
            cout<<k-cnt-1;///'-1' since the starting node is also counted as viewed.
            cout<<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<".\n";
        }
    }
    return 0;
}
