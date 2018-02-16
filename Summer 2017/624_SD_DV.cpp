/**Just iterating through all the subsets**/
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
    int n,t,maxim,sum;
    while(cin>>n)
    {
        maxim=-1;
        cin>>t;
        vi tracklen;
        tracklen.resize(t);
        vi anstracks;
        for(int i=0;i<t;i++) cin>>tracklen[i];
        for (int i = 0; i < (1 << t); i++) { // for each subset, O(2^n)
            vi tempanstracks;
            sum = 0;
            for (int j = 0; j < t; j++) // check membership, O(n)
                if (i & (1 << j)) // test if bit ‘j’ is turned on in subset ‘i’?
                {
                    sum += tracklen[j]; // if yes, process ‘j’
                    tempanstracks.push_back(j);
                }
            if(sum<=n&&sum>maxim)
            {
                maxim=sum;
                anstracks.clear();
                anstracks=tempanstracks;
                if(sum==n) break;
            }
        }
        for(int i=0;i<anstracks.size();i++) cout<<tracklen[anstracks[i]]<<" ";
        cout<<"sum:"<<maxim<<"\n";
    }
    return 0;
}

