#include<bits/stdc++.h>
using namespace std;

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


int main() {
	int m,n,a,b ,cases=0;
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while (scanf("%d %d", &n, &m)&&n+m!=0) {
        cases++;
        UFDS uf(n+1);
		for(int i=1;i<=m;i++)
        {
            scanf("%d %d", &a, &b);
            uf.unionSet(a,b);
        }
        printf("Case %d: %d\n",cases,uf.numDisjointSets()-1);
		//cout<<uf.numDisjointSets()-1<<endl;
	}

	return 0;
}
