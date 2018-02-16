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
    llu fib[50],total[50],males[50];
    fib[0]=total[0]=1;
    fib[1]=1;
    total[1]=2;
    males[0]=0;
    males[1]=1;
    for(int i = 2;i<47;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        males[i]=males[i-1]+fib[i-1];
        total[i]=total[i-1]+fib[i];
    }
    int n;
    while(cin>>n&&n!=-1)
    {
        cout<<males[n]<<" "<<total[n]<<"\n";
    }
    return 0;
}

