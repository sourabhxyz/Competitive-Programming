
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
typedef pair<int,pair<int,char> > iic;
typedef vector<iic> viic;
typedef pair<int,char> ic;
typedef pair<int,pair<string, bool> > isb;
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
#define MAX_V 2=101

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n;
    map<string,int> data;
    map<string,int> names;
    map<string,int>::iterator it;
    string line,ss,check,compname;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        compname="";
        stringstream strm;
        getline(cin,line);
        strm<<line;
        strm>>check;
        if(data.find(check)==data.end())
        {
            data[check]=0;
        }
        while(strm>>ss)
        {
            compname+=ss;
            compname+=" ";

        }
        if(names.find(compname)==names.end())
            {
                data[check]++;
                names[compname]=0;
            }
    }
    for(it=data.begin();it!=data.end();it++)
    {
        cout<<it->first<<" "<<it->second<<"\n";
    }
}


