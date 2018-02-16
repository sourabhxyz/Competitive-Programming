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
typedef map<int,pair<int,int>> miii;
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
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define EPS 1e-7
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    map<llu,int> data;
    llu fib[110];
    fib[0]=1;
    fib[1]=1;
    data[1]=1;
    llu arr[100];
    for(int i=2;i<101;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        data[fib[i]]=i;
    }
    string line;
    string ans;
    int t,n,j,d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans.clear();
        for(int i=0;i<100;i++)
        {
            ans.push_back('0');
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin.ignore();
        getline(cin,line);
        j=0;
        for(int i=0;i<line.size()&&j<n;i++)
        {
            if(line[i]<65||line[i]>90)
            {
                continue;
            }
            d=data.find(arr[j])->second;
            ans[d-1]=line[i];
            j++;
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='0')
            {
                if(ans[i-1]!='0')
                {
                    ans[i]=' ';
                }
            }
        }
        while(ans[ans.size()-1]==' ')
            ans.erase(ans.begin()+ans.size()-1);
        //ans.erase(ans.begin()+ans.size()-1);
        cout<<ans<<"\n";
    }
    return 0;
}
