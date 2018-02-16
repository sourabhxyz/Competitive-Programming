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
int calc[100003];
int ans[100003];
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    FileIn("in");
    FileOut("out");
    memset(calc,0,sizeof calc);
    for(int i = 1 ; i<317;i++)
    {
        calc[i*i]=1;
    }
    ans[1]=1;
    for(int i=2;i<=100000;i++)
    {
        if(calc[i]) ans[i]=ans[i-1]+1;
        else ans[i]=ans[i-1];
    }
    int a,b;
    while(cin>>a>>b&&(a||b))
    {
        if(calc[a])
        cout<<ans[b]-ans[a]+1<<"\n";
        else
            cout<<ans[b]-ans[a]<<"\n";
    }

}

