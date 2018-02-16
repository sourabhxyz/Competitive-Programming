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
vi  AdjList[100];
int dfsNumberCounter,dfsRoot,rootChildren;
vi dfs_num,dfs_low,dfs_parent;
vector<bool> articulation_vertex;
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == UNVISITED) { // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u]) // for articulation point
            articulation_vertex[u] = true; // store this information first IMP NOTE: I have removed third if.
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,cnt,n,temp;
    string line;
    while(cin>>V&&V)
    {
        cin.ignore();
        for(int i=0;i<100;i++)
            AdjList[i].clear();
        while(getline(cin,line)&&line!="0")
        {
            stringstream strm;
            strm<<line;
            strm>>n;
            while(strm>>temp)
            {
                AdjList[n-1].push_back(temp-1);
                AdjList[temp-1].push_back(n-1);
            }
        }
        dfsNumberCounter = 0; dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
        dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);
        cnt=0;
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == UNVISITED) {
                dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);  // special case
            }
        for (int i = 0; i < V; i++)
        if (articulation_vertex[i])
            cnt++;
        cout<<cnt<<"\n";
    }
    return 0;
}
