/**It shows that the grid need not be square*/
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
#define INF 100000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");

    int n,m,A[110][110],subRect;
    while(cin>>m>>n&&(n||m))
    {
    	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            cin>>A[i][j];
            if(A[i][j]==1) A[i][j]=-INF;
            else A[i][j] = 1;
        	if (i > 0) A[i][j] += A[i - 1][j]; /// if possible, add from top
        	if (j > 0) A[i][j] += A[i][j - 1]; /// if possible, add from left
        	if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1]; /// avoid double count
    	} /// inclusion-exclusion principle
    	int maxSubRect = 0; // the lowest possible value for this problem
   		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) // start coordinate
        	for (int k = i; k < m; k++) for (int l = j; l < n; l++) { // end coord
            	subRect = A[k][l]; // sum of all items from (0, 0) to (k, l): O(1)
            	if (i > 0) subRect -= A[i - 1][l]; // O(1)
            	if (j > 0) subRect -= A[k][j - 1]; // O(1)
            	if (i > 0 && j > 0) subRect += A[i - 1][j - 1]; // O(1)
            	maxSubRect = max(maxSubRect, subRect); } // the answer is here
        cout<<maxSubRect<<"\n";
	}
	return 0;
}

