/**First We can turn the n × n
input matrix into an n × n cumulative sum matrix where A[i][j] no longer contains its
own value, but the sum of all items within sub-matrix (0, 0) to (i, j). This can be done
simultaneously while reading the input and still runs in O(n^2).
With the sum matrix, we can answer the sum of any sub-matrix (i, j) to (k, l) in O(1)
using the code below*/
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
    int t;
    bool first = true;
    string line;
    cin>>t;
    int n,A[26][26],subRect;
    cin.ignore();
    getline(cin,line);
    while(t--)
    {
        if(first) first = false;
        else cout<<"\n";
        int n = 0;
		while(getline(cin,line))
        {
            if(line=="") break;

            for(int j = 0;j<line.size();j++)
            {
                if(line[j]=='1') A[n][j] = 1;
                else A[n][j] = -INF;
            }
            n++;
        }
    	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        	if (i > 0) A[i][j] += A[i - 1][j]; /// if possible, add from top
        	if (j > 0) A[i][j] += A[i][j - 1]; /// if possible, add from left
        	if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1]; /// avoid double count
    	} /// inclusion-exclusion principle
    	int maxSubRect = 0; // the lowest possible value for this problem
   		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coordinate
        	for (int k = i; k < n; k++) for (int l = j; l < n; l++) { // end coord
            	subRect = A[k][l]; // sum of all items from (0, 0) to (k, l): O(1)
            	if (i > 0) subRect -= A[i - 1][l]; // O(1)
            	if (j > 0) subRect -= A[k][j - 1]; // O(1)
            	if (i > 0 && j > 0) subRect += A[i - 1][j - 1]; // O(1)
            	maxSubRect = max(maxSubRect, subRect); } // the answer is here
        cout<<maxSubRect<<"\n";
	}
	return 0;
}

