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
int maxim[505][505*4],minim[505][505*4];
vi arr;
int ansmax,ansmin;
int left (int p) { return p << 1; } // same as binary heap operations
int right(int p) { return (p << 1) + 1; }
void build(int r,int p, int L, int R) { // O(n)
        if (L == R) // as L == R, either one is fine
            maxim[r][p]=minim[r][p]=arr[L];
        else { // recursively compute the values
            build(r,left(p) , L , (L + R) / 2);
            build(r,right(p), (L + R) / 2 + 1, R );
            maxim[r][p]=max(maxim[r][left(p)],maxim[r][right(p)]);
            minim[r][p]=min(minim[r][left(p)],minim[r][right(p)]);
        }
    }
void rq(int r,int p, int L, int R, int i, int j) { // O(log n)
        if (i > R || j < L || L > R) return; // current segment outside query range
        if (L >= i && R <= j){
            ansmax=max(ansmax,maxim[r][p]);
            ansmin=min(ansmin,minim[r][p]);
            return;
        }
        // compute the min position in the left and right part of the interval
        rq(r,left(p) , L , (L+R) / 2, i, j);
        rq(r,right(p), (L+R) / 2 + 1, R , i, j);
    }
void Update(int r, int p, int L, int R, int V,int val) {///V denotes column
	if (V<L || R<V || L > R) return;    
	if (L==R) {
        maxim[r][p] = minim[r][p] = val;
        return;
    }
    int mid = (L+R)/2;
    Update(r, left(p), L, mid,V, val);
    Update(r, right(p), mid+1, R,V, val);
    maxim[r][p] = max(maxim[r][left(p)], maxim[r][right(p)]);
    minim[r][p] = min(minim[r][left(p)], minim[r][right(p)]);
}

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n,q,u,v,val,r1,r2;
    char c;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        build(i,1,0,n-1);
    }
    cin>>q;
    while(q--)
    {
        cin>>c;
        if(c=='c')
        {
            cin>>u>>v>>val;
            u--; v--;
            Update(u,1,0,n-1,v,val);
        }
        else
        {
            cin>>r1>>u>>r2>>v;
            u--; r1--; r2--; v--;
            ansmax=-INF; ansmin=INF;
            for(int i=r1;i<=r2;i++)
            {
                rq(i,1,0,n-1,u,v);
            }
            cout<<ansmax<<" "<<ansmin<<"\n";
        }
    }

    return 0;
}

