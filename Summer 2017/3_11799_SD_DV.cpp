#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,n,temp,maxim;
    //FileIn("in");
    //FileOut("out");
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        maxim=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp>maxim)
            {
                maxim=temp;
            }
        }
        printf("Case %d: %d\n",t,maxim);

    }
    return 0;
}
