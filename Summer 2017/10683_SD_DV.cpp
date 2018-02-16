/**24 hours == 10 decimal hours
 i.e. 24*60*60*100 normal cc == 10*(100^3) decimal cc
 i.e. 1 decimal cc == 0.864 normal cc. 
 now 1nc*(1dc/0.864nc) would give us in dc**/
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
    string line;
    llu hhi,mmi,ssi,cci,hf,mmf,ssf,ccf,conv;
    while(cin>>line)
    {
        hhi = line[0]-'0';
        hhi*=10;
        hhi += line[1]-'0';
        mmi = line[2]-'0';
        mmi*=10;
        mmi += line[3]-'0';
        ssi = line[4]-'0';
        ssi*=10;
        ssi += line[5]-'0';
        cci = line[6]-'0';
        cci*=10;
        cci += line[7]-'0';
        conv=hhi*60*60*100;
        conv+=mmi*60*100;
        conv+=ssi*100;
        conv +=cci;
        int ans = (int)conv/0.864;
        cout<<setfill('0')<<setw(7)<<ans<<'\n';
        //cout<<fixed<<setprecision(0)<<conv/0.864<<"\n";
    }
    return 0;
}

