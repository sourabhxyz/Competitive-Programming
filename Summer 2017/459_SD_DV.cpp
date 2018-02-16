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
vi AdjList[27];
int cnt;
vi dfs_num; // global variable, initially all values are set to UNVISITED
void dfs(int u) { // DFS for normal usage: as graph traversal algorithm
    dfs_num[u] = VISITED; // important: we mark this vertex as visited
    for (int j = 0; j < (int)AdjList[u].size(); j++) { // default DS: AdjList
        int v = AdjList[u][j]; // v is a (neighbor, weight) pair
        if (dfs_num[v] == UNVISITED) // important check to avoid cycle
            dfs(v); // recursively visits unvisited neighbors of vertex u
        }
} // for simple graph traversal, we ignore the weight stored at v.second
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int t;
    cin>>t;
    char c1,c2;
    cin.ignore();
    string line;
    int n,a,b;
    getline(cin,line);
    while(t--)
    {
        cin>>c1;
        cin.ignore();
        n=c1-'A';
        while(getline(cin,line)&&line!="")
        {
            c1=line[0];
            c2=line[1];
            a=c1-'A';
            b=c2-'A';
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        int numCC = 0;
        cnt=0;
        dfs_num.assign(n+1, UNVISITED); // sets all vertices’ state to UNVISITED
        for (int i = 0; i <n+1 ; i++) // for each vertex i in [0..V-1]
        {
            if (dfs_num[i] == UNVISITED) // if vertex i is not visited yet
                dfs(i),cnt++; // 3 lines here!
        }
        cout<<cnt<<"\n";
        if(t!=0)
            cout<<"\n";
        for(int i=0;i<n+1;i++)
            AdjList[i].clear();
    }
    return 0;
}
