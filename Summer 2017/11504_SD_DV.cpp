/*Consider the test case:
1
12 13
1 2
2 3
3 4
4 1
6 3
6 7
7 8
8 9
9 6
12 2
12 10
10 11
11 12
----
The output should be:
3
-----*/
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
vector<vector<int> >  AdjList;
int dfsNumberCounter,numSCC;
vi dfs_num, dfs_low, S, visited,tocheck; // global variables
bool arr[100000];
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v]) // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
            numSCC++;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            tocheck[v]=numSCC;
            if (u == v) break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,E,t,u,v,res;
    cin>>t;
    while(t--)
    {
        memset(arr,1,sizeof arr);
        cin>>V>>E;
        tocheck.clear();
        tocheck.resize(V);
        AdjList.clear();
        AdjList.resize(V);
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            AdjList[u-1].push_back(v-1);
        }
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == UNVISITED)
                tarjanSCC(i);
        for(int i=0;i<V;i++) /**In this loop what we are doing is that, we are marking 
            all those numSCC's as false if they are not forming cycles (excluding their
            one member, only those numSCC's which are formed by a cycle are marked as true.
            thus know if we iterate through all the numSCC's only those which are true get
            accepted and thus contribute to the result */
        {
            int x=tocheck[i];
            for(int j=0;j<AdjList[i].size();j++)
            {
                int k=tocheck[AdjList[i][j]];
                if(k!=x) arr[k]=false; 
            }
        }
        res=0;
        for(int i=1;i<=numSCC;i++)
        {
            if(arr[i]) res++;
        }
        cout<<res<<"\n";
    }
    return 0;
}

