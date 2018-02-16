/**Just iterate through all the subsets**/
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
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int t,n,p,sum,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        vi barlen;
        barlen.resize(p);
        for(i=0;i<p;i++)
        {
            cin>>barlen[i];
        }
        for (i = 0; i < (1 << p); i++) { // for each subset, O(2^n)
            sum = 0;
            for (int j = 0; j < p; j++) // check membership, O(n)
                if (i & (1 << j)) // test if bit ‘j’ is turned on in subset ‘i’?
                    sum += barlen[j]; // if yes, process ‘j’
            if (sum == n) break; // the answer is found: bitmask ‘i’
        }
        if(i!=(1<<p)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

