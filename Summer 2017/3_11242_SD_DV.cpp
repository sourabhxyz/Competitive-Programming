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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
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
    int f,r,fteeth[10],rteeth[10],k;
    float ratio[100],spread[99],max;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&f)&&f)
    {
        k=0;
        max=-1;
        memset(fteeth,0,sizeof(fteeth));
        memset(rteeth,0,sizeof(rteeth));
        memset(ratio,0,sizeof(ratio));
        scanf("%d",&r);
        for(int i=0;i<f;i++)
        {
            scanf("%d",&fteeth[i]);
        }
        for(int i=0;i<r;i++)
        {
            scanf("%d",&rteeth[i]);
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<f;j++)
            {
                ratio[k]=rteeth[i]*1.0/fteeth[j];
                k++;
            }
        }
        sort(ratio,ratio+f*r);
        for(int i=0;i<f*r-1;i++)
        {
            spread[i]=ratio[i+1]/ratio[i];
            spread[i]=round(spread[i]*100);
            spread[i]/=100;
            if(max<spread[i])
            {
                max=spread[i];
            }
        }
        printf("%0.2f\n",max);
    }

    return 0;
}
