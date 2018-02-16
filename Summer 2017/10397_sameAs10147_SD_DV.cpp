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
typedef complex<double> point;
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
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
   // FileOut("out");
    vector<point> data;
    point temp;
    bool first=true;
    bool newh=false;
    int x,y;
    vector< pair<double, ii > > EdgeList; // (weight, two vertices) of the edge
    int V,u,v,m;
    double ans;
    while(cin>>V)
    {
        ans=0;
        EdgeList.clear();
        data.clear();
        for(int i=0;i<V;i++)
        {
            cin>>x>>y;
            temp.real(x);
            temp.imag(y);
            data.push_back(temp);
        }
        UFDS UF(V); // all V are disjoint sets initially
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            if (!UF.isSameSet(u-1, v-1)) { // check
                UF.unionSet(u-1, v-1); // link them
            }
        }
        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)///notice: j = i+1
            {
                EdgeList.push_back(make_pair(abs(data[i]-data[j]),ii(i,j)));
            }
        }
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        // note: pair object has built-in comparison function
        for (int i = 0; i < EdgeList.size(); i++) { // for each edge, O(E)
            pair<double, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                UF.unionSet(front.second.first, front.second.second); // link them
                ans+=front.first;
            }  // note: the runtime cost of UFDS is very light
        }
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
    return 0;
}
