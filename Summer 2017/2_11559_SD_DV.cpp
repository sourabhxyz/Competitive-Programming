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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //FileIn("in");
    //FileOut("out");
    int h,b,n,w,hotel,temp;
    llu net,maxim;
    while(scanf("%d%d%d%d",&n,&b,&h,&w)==4)
    {
        maxim=10000000;
        for(int i=0;i<h;i++)
        {
            net=0;
            scanf("%d",&hotel);
            for(int j=0;j<w;j++)
            {
                scanf("%d",&temp);
                if(temp>=n)
                {
                    net=hotel*n;
                }
            }
            if(net<maxim&&net!=0)
            {
                maxim=net;
            }
        }
        if(maxim<=b)
        {
            printf("%llu\n",maxim);
        }
        else
            printf("stay home\n");
    }
    return 0;
}
