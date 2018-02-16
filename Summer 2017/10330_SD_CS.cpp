
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
typedef pair<int,pair<int,char> > iic;
typedef vector<iic> viic;
typedef pair<int,char> ic;
typedef pair<int,pair<string, bool> > isb;
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
#define MAX_V 201
int res[205][205], mf, f, s=0, t; // global variables
vi p; // p stores the BFS spanning tree from s
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f; }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,E,u_,v_,b,B,D;
    while(cin>>V)
    {
        for(int i=0;i<201;i++)
        {
            for(int j=0;j<201;j++)
                res[i][j]=0;
        }
        for(int i=1;i<=V;i++)
        {
            cin>>b;
            res[i][i+100]=b;
            //res[i+100][i]=b; //Even gets accepted after uncommenting this line
        }
        cin>>E;
        for(int i=0;i<E;i++)
        {
            cin>>u_>>v_>>b;

                res[u_+100][v_]=b;
                //res[v_-1+50][u_-1]=b;

        }
        cin>>B>>D;
        for(int i=0;i<B;i++)
        {
            cin>>u_;
            res[0][u_]=INF;
        }
        for(int i=0;i<D;i++)
        {
            cin>>u_;
            res[u_+100][V+1]=INF;
        }
        t=V+1;
        mf = 0; // mf stands for max_flow
        while (1) { // O(VE^2) (actually O(V^3 E) Edmonds Karp’s algorithm
            f = 0;
            // run BFS, compare with the original BFS shown in Section 4.2.2
            vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(MAX_V, -1); // record the BFS spanning tree, from s to t!
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break; // immediately stop BFS if we already reach sink t
                for (int v = 0; v < MAX_V; v++) // note: this part is slow
                    if (res[u][v] > 0 && dist[v] == INF)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u; // 3 lines in 1!
            }
            augment(t, INF); // find the min edge weight ‘f’ in this path, if any
            if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
            mf += f; // we can still send a flow, increase the max flow!
        }
        cout<<mf;
        cout<<"\n";
    }
}
