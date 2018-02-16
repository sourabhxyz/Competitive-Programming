
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
vector<vii> AdjList;
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int cases,V,E,x,y,t;
    cin>>cases;
    while(cases--)
    {
        cin>>V>>E;
        AdjList.clear();
        AdjList.resize(V+5);
        for(int i =0;i<E;i++)
        {
            cin>>x>>y>>t;
            AdjList[x].push_back(ii(y,t));
        }
        vi dist(V, INF); dist[0] = 0;
        for (int i = 0; i < V - 1; i++) // relax all E edges V-1 times
            for (int u = 0; u < V; u++) // these two loops = O(E), overall O(VE)
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j]; // record SP spanning here if needed
                    dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
                }
        // after running the O(VE) Bellman Ford’s algorithm shown above
        bool hasNegativeCycle = false;
        for (int u = 0; u < V and !hasNegativeCycle; u++) // one more pass to check
            for (int j = 0; j < (int)AdjList[u].size() and !hasNegativeCycle; j++) {
                ii v = AdjList[u][j];
                if (dist[v.first] > dist[u] + v.second) // if this is still possible
                    hasNegativeCycle = true; // then negative cycle exists!
        }
        hasNegativeCycle?cout<<"possible\n" : cout<<"not possible\n";
    }


    return 0;
}

