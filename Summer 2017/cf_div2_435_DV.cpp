/**Problem:
 * Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked
 * them to add edges to it in such a way, that the graph is still bipartite.
 * Besides, after adding these edges the graph should be simple
 * (doesn't contain loops or multiple edges). What is the maximum number of
 * edges they can add?
 *
 * Solution:
 *The tree itself is bipartite so we can run a dfs to partition the
 * tree into the 2 sets (called bicoloring), We can't add an edge between
 * any 2 nodes in the same set and we can add an edge between every 2 nodes
 * in different sets, so let the number of nodes in the left set be l and
 * the number of nodes in the right set be r, The maximum number of edges
 * that can exist is l?*?r, but n?-?1 edges already exist so the maximum number
 * of edges to be added is l?*?r?-?(n?-?1).
 * Time complexity : O(n)
 */
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
typedef vector<vi > vvi;

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
#define EPS 1e-8
#define MAX_V 50

vector<vi> AdjList;

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n;
    cin>>n;
    vi AdjList[n+5];
    for(int i = 0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);

    }
    vector<int> set1;
    vector<int> set2;
    queue<int> q; q.push(1);
    vi color(n+2, INF); color[1] = 0;
    bool isBipartite = true; // addition of one boolean flag, initially true
    while (!q.empty() & isBipartite) { // similar to the original BFS routine
        int u = q.front(); q.pop();
        if(color[u]==0) set1.push_back(u);
        else set2.push_back(u);
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
    cout<<set1.size()*set2.size()-(n-1)<<'\n';
    return 0;
}
