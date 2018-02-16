#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string, int> msi;
typedef map<int,pair<int,int> > miii;
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 50000000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n,l,a,b;
    while(cin>>n&&n)
    {
        vi AdjList[n];
        cin>>l;
        for(int i=0;i<l;i++)
        {
            cin>>a>>b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        queue<int> q; q.push(0);
        vi color(n, INF); color[0] = 0;
        bool isBipartite = true; // addition of one boolean flag, initially true
        while (!q.empty() & isBipartite) { // similar to the original BFS routine
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (color[v] == INF) { // but, instead of recording distance,
                    color[v] = 1 - color[u]; // we just record two colors {0, 1}
                    q.push(v);
                }
                else if (color[v] == color[u]) { // u & v.first has same color
                    isBipartite = false; break; // we have a coloring conflict
                }
            }
        }
        if(isBipartite)
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";

    }
    return 0;
}
