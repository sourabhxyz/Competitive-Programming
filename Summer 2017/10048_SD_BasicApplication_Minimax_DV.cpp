
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
int graph[100+5][100+5];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,E,Q,u,v,sound,cases=0;
    while(cin>>V>>E>>Q&&(V||E||Q))
    {
        if(cases>0)
            cout<<"\n";
        cases++;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i==j) graph[i][j]=0;
                else
                    graph[i][j]=INF;
            }
        }
        for(int i=0;i<E;i++)
        {
            cin>>u>>v>>sound;
            graph[u-1][v-1]=graph[v-1][u-1]=sound;
        }
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
        cout<<"Case #"<<cases<<"\n";
        for(int i=0;i<Q;i++)
        {
            cin>>u>>v;
            if(graph[u-1][v-1]!=INF) cout<<graph[u-1][v-1]<<"\n";
            else cout<<"no path\n";
        }
    }
    return 0;
}
