#include <bits/stdc++.h>
using namespace std;
int n;
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
int enemyID(int x)
{
    return x+n;
}
int main() {

    cin>>n;
    UFDS uf(2*n);
    int c,x,y;
    while(cin>>c>>x>>y&&(c||x||y))
    {
        switch(c)
        {
            case 1: if(uf.isSameSet(x,enemyID(y))||uf.isSameSet(y,enemyID(x))) cout<<"-1\n";
                else uf.unionSet(x,y),uf.unionSet(enemyID(x),enemyID(y));
                break;
            case 2: if(uf.isSameSet(x,y)||uf.isSameSet(enemyID(x),enemyID(y))) cout<<"-1\n";
                else uf.unionSet(x,enemyID(y)),uf.unionSet(y,enemyID(x));
                break;
            case 3: if(uf.isSameSet(x,y)||uf.isSameSet(enemyID(x),enemyID(y))) cout<<"1\n";
                else cout<<"0\n";
                break;
            case 4: if(uf.isSameSet(x,enemyID(y))||uf.isSameSet(y,enemyID(x))) cout<<"1\n";
                else cout<<"0\n";
                break;
        }
    }

	return 0;
}

