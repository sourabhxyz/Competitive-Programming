/**
Let a[i] be the number of ways i pairs of people can shake hands.

It's easy tell that a[0] = 1, a[1] = 1, a[2] = 2.

For larger n, imagine choosing an arbitrary pair of people to shake hands. 
You've now divided the circle into two smaller circles (one of which may have 0 people 
in it). The number of ways you can arrange the rest of the people is the product of the 
answers for the two smaller circles.

So for example, to compute n = 3:

a[3] = a[0]*a[2] + a[1]*a[1] + a[2]*a[0]
a[4] = a[0]*a[3] + a[1]*a[2] + a[2]*a[1] + a[3][0]

Or you can just output cat[n]...
**/

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
llu dp[11];
void init()
{
    memset(dp,0,sizeof dp);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<11;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]+=(dp[j]*dp[i-1-j]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    init();
    int n;
    bool first=true;
    while(cin>>n)
    {
        if(first) first=false;
        else cout<<"\n";
        cout<<dp[n]<<"\n";
    }
    return 0;
}

