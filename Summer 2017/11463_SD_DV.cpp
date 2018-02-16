/*With infinite soldiers, you may as well send each one out to a different building. 
Let s and t be the start and end locations. Let d[i][j] be the distance between i and j.
 This ith soldier needs d[s][i] + d[i][t] time to complete his mission.
So, the answer is the maximum across all 0 <= i < n of d[s][i] + d[i][t].
*/
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
int graph[105][105];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int t,V,E,u,v,s_,e_,maxim;
    cin>>t;
    for(int cases=1;cases<=t;cases++)
    {
        maxim=-1;
        cin>>V>>E;
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
            {
                if(i==j)
                    graph[i][j]=0;
                else
                    graph[i][j]=INF;
            }

        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            graph[u][v]=1;
            graph[v][u]=1;

        }
        cin>>s_>>e_;
        for (int k = 0; k < 100; k++) // remember that loop order is k->i->j
            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        for(int i=0;i<26;i++)
        {
            if(graph[s_][i]!=INF&&graph[i][e_]!=INF)
            if(maxim<graph[s_][i]+graph[i][e_])
                maxim=graph[s_][i]+graph[i][e_];
        }
        cout<<"Case "<<cases<<": "<<maxim<<"\n";
    }
    return 0;
}

