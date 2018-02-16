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
vi AdjList[100];
vi dfs_num;
vi ts; /// global vector to store the toposort in reverse order
void dfs2(int u)  /// different function name compared to the original dfs
{
    dfs_num[u] = VISITED;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == UNVISITED)
            dfs2(v);
    }
    ts.push_back(u); /// that’s it, this is the only change
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n,m,a,b;
    while(cin>>n>>m&&(n!=0||m!=0))
    {
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            AdjList[a-1].push_back(b-1);
        }
        ts.clear();
        dfs_num.assign(n, UNVISITED);
        for (int i = 0; i < n; i++) /// this part is the same as finding CCs
            if (dfs_num[i] == UNVISITED)
                dfs2(i);
        /// alternative, call: reverse(ts.begin(), ts.end()); first
        cout<<ts[ts.size()-1]+1;
        for (int i = (int)ts.size() - 2; i >= 0; i--) // read backwards
            cout<<" "<<ts[i]+1;//printf(" %d", ts[i]+1);
        cout<<"\n";//printf("\n");
    }
    return 0;
}
