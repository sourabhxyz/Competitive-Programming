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

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    llu fib[48];

    fib[0]=0;
    fib[1]=1;
    for(int i = 2;i<48;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int n;
    int t;
    string a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int temp = n;
        a.clear();
        for(int i = 0;i<48;i++) a.push_back('0');
        for(int j=47;j>=1;j--)
        {
            if(fib[j]<=n)
            {
                n-=fib[j];
                a[j-2]='1'; ///-2 because fib[2] is also 1;
            }
        }
        while(a[a.size()-1]!='1') a.pop_back();
        reverse(a.begin(),a.end());
        cout<<temp<<" = "<<a<<" (fib)\n";
    }

    return 0;
}

