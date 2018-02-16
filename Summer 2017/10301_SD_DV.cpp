#include <bits/stdc++.h>
using namespace std;
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
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
struct circle{
    double cx,cy,r;
};
bool overlap(circle a,circle b)///even if one circle is completely inside the other (i.e. no intersection), still this function returns true
{
    return sqrt((a.cx-b.cx)*(a.cx-b.cx)+(a.cy-b.cy)*(a.cy-b.cy))<(a.r+b.r)+1e-8;
}
bool contained(circle a, circle b)
{
    return (abs(a.r-b.r) +1e-9) > (sqrt((a.cx-b.cx)*(a.cx-b.cx)+(a.cy-b.cy)*(a.cy-b.cy)));
}

int main() {
    ios::sync_with_stdio(0);
    //FileIn("in");
    //FileOut("out");
    int n;
    while(cin>>n&&n!=-1)
    {
        cout<<"The largest component contains ";
        vector<circle> data;
        data.resize(n);
        UFDS uf(n);
        for(int i = 0;i<n;i++)
        {
            cin>>data[i].cx>>data[i].cy>>data[i].r;
        }
        for(int i= 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(overlap(data[i],data[j])&&!contained(data[i],data[j]))
                {
                    uf.unionSet(i,j);
                }
            }
        }
        int maxim = 0;
        for(int i = 0;i<n;i++)
        {
            int temp = uf.setSize(i);
            if(temp>maxim) maxim = temp;
        }
        if(maxim==1) cout<<"1 ring.\n";
        else cout<<maxim<<" rings.\n";
    }
	return 0;
}

