
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
#define MAX_V 101
int res[105][105], mf, f, s, t; // global variables
vector<vi> AdjList;
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
    int V,E,u_,v_,b,cases=0;
    while(cin>>V&&V)
    {
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
                res[i][j]=0;
        }
        cases++;
        cin>>s>>t>>E;
        for(int i=0;i<E;i++)
        {
            cin>>u_>>v_>>b;
            /*AdjList[u_-1].push_back(v_-1);
            AdjList[v_-1].push_back(u_-1);*/
            res[u_-1][v_-1]+=b;//just because of this fact that they would have 
            //provided us with multiple edges between the same node, is the only re
            //ason why we cant use adjlist...
            res[v_-1][u_-1]+=b;
        }
        s--;
        t--;
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
        cout<<"Network "<<cases<<"\n";
        cout<<"The bandwidth is "<<mf<<".\n\n";
    }
}

