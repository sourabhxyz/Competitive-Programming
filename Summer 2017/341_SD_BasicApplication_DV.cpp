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
vector<vii> AdjList;
vi p;
int s_;
void printPath(int u) { // extract information from ‘vi p’
    if (u == s_-1) { cout<<s_; return; } // base case, at the source s
    printPath(p[u]); // recursive: to make the output format: s -> ... -> t
    cout<<" "<<u+1;
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,e,b,del,end_,cases=0;
    while(cin>>V&&V)
    {
        cases++;
        p.clear();
        p.resize(V);
        AdjList.clear();
        AdjList.resize(V);
        for(int i=0;i<V;i++)
        {
            cin>>e;
            while(e--)
            {
                cin>>b>>del;
                AdjList[i].push_back(make_pair(b-1,del));
            }
        }
        cin>>s_>>end_;
        vi dist(V, INF); dist[s_-1] = 0; /// INF = 1B to avoid overflow
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s_-1)); ///Note: this greater<ii> and vector<ii> is
        ///is used to store elements in the increasing order instead of decreasing order.
        while (!pq.empty()) { /// main loop
            ii front = pq.top(); pq.pop(); /// greedy: get shortest unvisited vertex
            int d = front.first, u = front.second;
            if (d > dist[u]) continue; /// this is a very important check
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j]; /// all outgoing edges from u
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second; /// relax operation
                    p[v.first] = u;
                    pq.push(ii(dist[v.first], v.first));
                }   /// this variant can cause duplicate items in the priority queue
            }
        }
        cout<<"Case "<<cases<<": Path = ";
        printPath(end_-1);
        cout<<"; "<<dist[end_-1]<<" second delay\n";
    }
    return 0;
}
