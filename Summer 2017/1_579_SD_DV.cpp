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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    FileIn("in");
    FileOut("out");
    int h;
    double m;
    double houra,ma,ans;
    char c;
    while(cin>>h>>c>>m&&(h!=0||m!=0))
    {
        houra=h*30;
        houra=houra+(m/2);
        ma=m*6;
        ans=abs(houra-ma);
        if(ans>180)
            ans=abs(ans-360);
        printf("%0.3f\n",ans);
    }
    return 0;
}
