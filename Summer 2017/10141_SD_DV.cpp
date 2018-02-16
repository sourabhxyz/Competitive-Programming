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
struct sup{
    string name;
    int compilance;
    double price;
    int id;
};
bool cmp(sup a, sup b)
{
    if(a.compilance!=b.compilance) return a.compilance>b.compilance;
    if(abs(a.price-b.price)<1e-5) return a.id<b.id;
    else return a.price<b.price;
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    bool first = true;
    int n,p,cnt = 0;
    while(cin>>n>>p&&(n||p))
    {
        if(first) first = false;
        else cout<<'\n';
        cnt++;
        vector<sup> data;
        data.resize(n);
        string line,junk;
        double price;
        cin.ignore();
        for(int i =0;i<n;i++)
        {
            getline(cin,junk);
        }
        for(int i = 0;i<p;i++)
        {
            int m;
            getline(cin,line);
            cin>>price>>m;
            data[i].name=line;
            data[i].id = i;
            data[i].price = price;
            data[i].compilance=m;
            cin.ignore();
            for(int i = 0;i<m;i++)
                getline(cin,junk);
        }
        sort(data.begin(),data.end(),cmp);
        cout<<"RFP #"<<cnt<<"\n";
        cout<<data[0].name<<"\n";
    }
    return 0;
}

