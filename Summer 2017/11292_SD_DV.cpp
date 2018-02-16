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
#define EPS 1e-9
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n,m,j,i;
    llu cost;
    vector<int> dia,hie;
    dia.resize(20000);
    hie.resize(20000);
    while(cin>>n>>m&&(n||m))
    {
        cost=0;
        if(m<n)
        {
            cout<<"Loowater is doomed!\n";
            continue;
        }
        for(i=0;i<n;i++)
        {
            cin>>dia[i];
        }
        sort(dia.begin(),dia.begin()+n);
        for(i=0;i<m;i++)
        {
            cin>>hie[i];
        }
        sort(hie.begin(),hie.begin()+m);
        j=0;
        for(i=0;i<n;)
        {
            while(hie[j]<dia[i]&&j<m)
            {
                j++;
            }
            if(j!=m)
            {
                i++;
                cost+=hie[j];
                j++;
            }
            else
                break;
        }
        if(i==n)
            cout<<cost<<"\n";
        else
            cout<<"Loowater is doomed!\n";
    }
    return 0;
}
