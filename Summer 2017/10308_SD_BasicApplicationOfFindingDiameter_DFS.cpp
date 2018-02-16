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
vector<vii > AdjList;
int s;
vector<bool> visited;
int maxim,maxtag;
vi dist;
ii dfs(int u) { // DFS for normal usage: as graph traversal algorithm
    visited[u]=true;
    if(dist[u]>maxim)
    {
        maxim=dist[u];
        maxtag=u;
    }
    for (int j = 0; j < (int)AdjList[u].size(); j++) { // default DS: AdjList
        ii v = AdjList[u][j]; // v is a (neighbor, weight) pair

        if (!visited[v.first]) // important check to avoid cycle
        {
            dist[v.first]=dist[u]+v.second;
            dfs(v.first); // recursively visits unvisited neighbors of vertex u
        }
    }
    return make_pair(maxtag,maxim);
} 
void init()
{
        dist.assign(10000,INF);
        maxim=0;
        visited.assign(10003,0);
        dist[s]=0;
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    string line;
    int a,b,rl;
    ii ans;
    while(getline(cin,line))
    {

        AdjList.clear();
        AdjList.resize(10003);
        stringstream strm;
        strm<<line;
        strm>>a>>b>>rl;
        AdjList[a-1].push_back(ii(b-1,rl));
        AdjList[b-1].push_back(ii(a-1,rl));
        s=a;
        s--;
        while(getline(cin,line)&&line!="")
        {
            stringstream strm2;
            strm2<<line;
            strm2>>a>>b>>rl;
            AdjList[a-1].push_back(ii(b-1,rl));
            AdjList[b-1].push_back(ii(a-1,rl));
        }
        init();
        ans=dfs(s);
        s=ans.first;
        init();
        ans=dfs(s);
        cout<<ans.second<<"\n";
    }
    return 0;
}

