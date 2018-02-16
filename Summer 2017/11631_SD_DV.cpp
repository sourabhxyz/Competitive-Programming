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
class UFDS {
private:
	vector<int> p, rank, setSizes;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
			} else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
			numSets--;
		}
	}
	int setSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    vector< pair<int, ii> > EdgeList; // (weight, two vertices) of the edge
    int V,E,w,u,v,sum;
    while(cin>>V>>E&&(V||E))
    {
        sum=0;
        EdgeList.clear();
        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &u, &v, &w); // read the triple: (u, v, w)
            sum+=w;
            EdgeList.push_back(make_pair(w, ii(u, v)));  // (w, u, v)
        }
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        // note: pair object has built-in comparison function
        int mst_cost = 0;
        UFDS UF(V); // all V are disjoint sets initially
        for (int i = 0; i < E; i++) { // for each edge, O(E)
            pair<int, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                mst_cost += front.first; // add the weight of e to MST
                UF.unionSet(front.second.first, front.second.second); // link them
            }  // note: the runtime cost of UFDS is very light
        }
        // note: the number of disjoint sets must eventually be 1 for a valid MST
        printf("%d\n", sum-mst_cost);
    }
    return 0;
}
