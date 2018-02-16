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
int d(int n)
{
    int sum=n;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int dp[1000002];
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    memset(dp,0,sizeof dp);
    for(int i =1;i<=1000000;i++)
    {
        int sum = d(i);
        if(sum<=1000000)
        ++dp[sum];
    }
    for(int i = 1;i<=1000000;i++)
    {
        if(!dp[i]) cout<<i<<"\n";
    }

}

