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
ii bfs()
{
    vector<bool> visited(10003,0);
    visited[s]=true;
    int maxim=0,maxtag;
    vi dist(10000, INF); dist[s] = 0; // distance from source s to s is 0
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if(dist[u]>maxim)
            {
                maxim=dist[u];
                maxtag=u;
            }
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if(!visited[v.first])
                {
                    visited[v.first]=true;
                    dist[v.first]=dist[u]+v.second;
                    q.push(v.first);

                }
            }
        }
        return make_pair(maxtag,maxim);
}
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    string line;
    int a,b,rl,ansfinal;
    ii ans;
    while(getline(cin,line))
    {
        ansfinal=0;
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
        ans=bfs();
        //cout<<ans.first+1<<" "<<ans.second<<"\n";
        s=ans.first;
        ans=bfs();
        cout<<ans.second<<"\n";
    }
    return 0;
}

