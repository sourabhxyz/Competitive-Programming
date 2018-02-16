/**My solution, which although does not pass the test cases on udebug but gets
accepted in UVA**/
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
#define MAX_V 101
int res[105][105], mf, f, s=0, t; // global variables
vi p; // p stores the BFS spanning tree from s
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f; }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,E,u_,v_,b,ans;
    while(cin>>V>>E&&(V||E))
    {
        ans=0;
        t=V-1;
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
                res[i][j]=0;
        }
        for(int i=0;i<V-2;i++)
        {
            cin>>u_>>b;
            res[u_-1][u_-1+50]=b;
            res[u_-1+50][u_-1]=b;
        }
        for(int i=0;i<E;i++)
        {
            cin>>u_>>v_>>b;
            if(u_!=1&&v_!=V)
            {
                res[u_-1+50][v_-1]=b;
                res[v_-1+50][u_-1]=b;
            }
            else if(u_==1&&v_!=V)
            {
                res[u_-1][v_-1]=b;
                res[v_-1+50][u_-1]=b;

            }
            else if(u_!=1&&v_==V)
            {
                res[v_-1][u_-1]=b;
                res[u_-1+50][v_-1]=b;
            }
            else
            {
                res[u_-1][v_-1]=b;
                res[v_-1][u_-1]=b;
            }

        }
        mf = 0; // mf stands for max_flow
        while (1) { // O(VE^2) (actually O(V^3 E) Edmonds Karp’s algorithm
            f = 0;
            // run BFS, compare with the original BFS shown in Section 4.2.2
            vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(MAX_V, -1); // record the BFS spanning tree, from s to t!
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break; // immediately stop BFS if we already reach sink t
                for (int v = 0; v < MAX_V; v++) // note: this part is slow
                    if (res[u][v] > 0 && dist[v] == INF)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u; // 3 lines in 1!
            }
            augment(t, INF); // find the min edge weight ‘f’ in this path, if any
            if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
            mf += f; // we can still send a flow, increase the max flow!
        }
        cout<<mf;
        cout<<"\n";
    }
}
/***********************And this solution is faster by 0.02 sec and passes the 
test cases on udebug*****************************/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bitset>
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
using namespace std;

typedef vector<int> vi;

#define INF 1e9
#define MAX_V 105

int res[MAX_V][MAX_V], mf, f, s, t;
vector<vi> AdjList;
vi p;

int m, w, V;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void EdmondKarps() {
	mf = 0;
	while (1) {
		f = 0;
		bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)
			break;
		mf += f;
	}
}

int main() {
	FileIn("in");
    FileOut("out");
	while (scanf("%d %d", &m, &w), m || w) {
		V = m * 2 - 2;
		memset(res, 0, sizeof res);
		AdjList.assign(V, vi());

		s = 0;
		t = V - 1;

		for (int i = 0; i < m - 2; i++) {
			int id, c, u, v;
			scanf("%d %d", &id, &c);
			id--;
			u = id + id - 1;
			v = u + 1;

			res[u][v] = c;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		for (int i = 0; i < w; i++) {
			int id1, id2, c, u1, u2, v1, v2;
			scanf("%d %d %d", &id1, &id2, &c);
			id1--;
			id2--;

			if (id1 != 0 && id1 != m - 1) {
				u1 = id1 + id1 - 1;
				v1 = u1 + 1;
			} else {
				if (id1 == 0)
					u1 = v1 = 0;
				else
					u1 = v1 = V - 1;
			}

			if (id2 != 0 && id2 != m - 1) {
				u2 = id2 + id2 - 1;
				v2 = u2 + 1;
			} else {
				if (id2 == 0)
					u2 = v2 = id2;
				else
					u2 = v2 = V - 1;
			}

			res[v1][u2] = c;
			res[v2][u1] = c;
			AdjList[v1].push_back(u2);
			AdjList[u2].push_back(v1);
			AdjList[v2].push_back(u1);
			AdjList[u1].push_back(v2);
		}

		EdmondKarps();
		printf("%d\n", mf);
	}

	return 0;
}
