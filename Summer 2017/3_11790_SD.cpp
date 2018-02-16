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
int h[2005],w[2005];
int mem[2005],mem2[2005];
int lis(int i)
{
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int res = w[i];
    for (int j = 0; j < i; j++)
    {
        if (h[j] < h[i])
        {
            res = max(res, w[i] + lis(j));
        }
    }
    mem[i] = res;
    return res;
}
int lds(int i)
{
    if (mem2[i] != -1)
    {
        return mem2[i];
    }
    int res = w[i];
    for (int j = 0; j < i; j++)
    {
        if (h[j] > h[i])
        {
            res = max(res, w[i] + lds(j));
        }
    }
    mem2[i] = res;
    return res;
}
int main() {
    //FileIn("in");
    //FileOut("out");
    int t,n,j,inc,dec,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        memset(mem, -1, sizeof(mem));
        memset(mem2, -1, sizeof(mem2));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
        }
        inc = 0;
        dec=0;
        for (int i = 0; i < n; i++)
        {
            inc = max(inc, lis(i));
            dec=max(dec,lds(i));
        }
        printf("Case %d. ",cases);
        inc>=dec?printf("Increasing (%d). Decreasing (%d).\n",inc,dec):printf("Decreasing (%d). Increasing (%d).\n",dec,inc);

    }

    return 0;
}
