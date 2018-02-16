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

vector<int> a;
int mem[33000];
int lds(int i)
{
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] > a[i])
        {
            res = max(res, 1 + lds(j));
        }
    }
    mem[i] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int x,caseno=0;
    while(cin>>x&&x!=-1)
    {
        if(caseno>0) cout<<"\n";
        caseno++;
        a.clear();
        memset(mem, -1, sizeof(mem));
        a.push_back(x);
        while(cin>>x&&x!=-1)
        {
            a.push_back(x);
        }
        int mx = 0;
        for (int i = 0; i < a.size(); i++)
        {
            mx = max(mx, lds(i));
        }
        cout<<"Test #"<<caseno<<":\n";
        cout<<"  maximum possible interceptions: "<<mx<<"\n";
    }
	return 0;
}

