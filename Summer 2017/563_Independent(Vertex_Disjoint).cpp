
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
typedef pair<int,pair<int,char> > iic;
typedef vector<iic> viic;
typedef pair<int,char> ic;
typedef pair<int,pair<string, bool> > isb;
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
#define MAX 2*52*52+10
vector<int > edge[MAX];
int cap[MAX][MAX];
int mf, f,s,t; // global variables
vi p; // p stores the BFS spanning tree from s
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, cap[p[v]][v]));
    cap[p[v]][v] -= f; cap[v][p[v]] += f; }
}
void BuildGraph(int S, int T, int H, int W);
int maxFlow()
{
	mf = 0;
        while (1) { // now a true O(VE^2) Edmonds Karp’s algorithm
            f = 0;
            bitset<MAX> vis; vis[s] = true; // we change vi dist to bitset!
            queue<int> q; q.push(s);
            p.assign(MAX, -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int j = 0; j < (int)edge[u].size(); j++) {
                    int v = edge[u][j]; // we use vector<vi> edge
                    if (cap[u][v] > 0 && !vis[v])
                    vis[v] = true, q.push(v), p[v] = u;
                }
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }
        return mf;
}
int main()
{
    int Case, H, W, B, x, y;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d %d", &H, &W, &B);

        s = 0;      // super source
        t = 1;      // super sink

        for (int i = 0; i <= 2*(H+1)*W; ++i) edge[i].clear();
        memset(cap, 0, sizeof(cap));

        BuildGraph(s, t, H, W);

        for (int i = 0; i < B; ++i) {
            scanf("%d %d", &x, &y);
            cap[s][(x*H+y)*2] = 1;
            edge[s].push_back((x*H+y)*2);
        }

        if (maxFlow() == B) puts("possible");
        else puts("not possible");
    }
}
void BuildGraph(int S, int T, int H, int W)
{//Basically in the following what we are doing is that we are hashing
//each coordinate(a,b) to a unique integer by using the formula
//i*H+j
/**Eg: Consider we have 3x3 grid, so:
	(1,1)=4  (1,2)=5  (1,3)=6
	(2,1)=7  (2,2)=8  (2,3)=9
	(3,1)=10 (3,2)=11 (3,3)=12
	Now if we were to do u to u' if we go like i*H+j+1 we land into collisions,
	so lets try; (i*H+j)*2
	(1,1)=8   (1,2)=10   (1,3)=12
	(2,1)=14  (2,2)=16   (2,3)=18
	(3,1)=20  (3,2)=22   (3,3)=24
	And now we can easily map from u to u' */
	for (int j = 1; j <= W; ++j)
    {
    	for (int i = 1; i <= H; ++i)
        {
            cap[(i*H+j)*2][(i*H+j)*2+1] = 1;     // u  to u'
            edge[(i*H+j)*2].push_back((i*H+j)*2+1);

            cap[(i*H+j)*2+1][((i-1)*H+j)*2] = 1; // u' to up
            edge[(i*H+j)*2+1].push_back(((i-1)*H+j)*2);

            cap[(i*H+j)*2+1][((i+1)*H+j)*2] = 1; // u' to down
            edge[(i*H+j)*2+1].push_back(((i+1)*H+j)*2);

            cap[(i*H+j)*2+1][(i*H+j-1)*2] = 1;   // u' to left
            edge[(i*H+j)*2+1].push_back((i*H+j-1)*2);

            cap[(i*H+j)*2+1][(i*H+j+1)*2] = 1;   // u' to right
            edge[(i*H+j)*2+1].push_back((i*H+j+1)*2);

            if (i == 1 || j == 1 || i == H || j == W) {// if on the edge
                cap[(i*H+j)*2+1][T] = 1;               // connect u' to the T
                edge[(i*H+j)*2+1].push_back(T);
            }
        }
    }
}

