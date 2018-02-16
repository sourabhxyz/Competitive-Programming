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
vi dfs_num, dfs_low, S, visited; // global variables
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
    int V,E;
    string line,line2;
    map<string,int> data;
    while(cin>>V>>E&&(V||E))
    {
        cin.ignore();
        AdjList.clear();
        AdjList.resize(V);
        for(int i=0;i<V;i++)
        {
            getline(cin,line);
            data[line]=i;
        }

        for(int i=0;i<E;i++)
        {
            getline(cin,line);
            getline(cin,line2);
            AdjList[data[line]].push_back(data[line2]);
        }
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == UNVISITED)
                tarjanSCC(i);
        cout<<numSCC<<"\n";
    }
    return 0;
}
