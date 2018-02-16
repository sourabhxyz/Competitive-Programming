/*Consider the first train car selected, suppose it is car i. From that single starting point, 
the train will grow in two independent directions: increasing weight and decreasing weight. 
Decreasing weights will go in the back and increasing weights in the front. To maximize the 
overall size of the train, you want to maximize the size of the increasing sequence plus the 
size of the decreasing sequence. You should therefore calculate this quantity for each possible 
starting car i and see for which car it is greatest. You subtract 1 when calculating the train 
size because both the increasing and decreasing sequences share the first car as a starting point, 
so it gets double-counted if you were to just add lis (i) and lds (i).
IMP NOTE: i have reversed the arrays because we dont want lis ending at i, but we want lis beginning
at i...
*/
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
int a[2005],b[2005];
int mem[2005],mem2[2005];
int lis(int i)
{
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++)
    {
        if (b[j] > b[i])
        {
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
}
int lis2(int i)
{
    if (mem2[i] != -1)
    {
        return mem2[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++)
    {
        if (b[j] < b[i])
        {
            res = max(res, 1 + lis2(j));
        }
    }
    mem2[i] = res;
    return res;
}
int main() {
    //FileIn("in");
    //FileOut("out");
    int t,n,j;
    scanf("%d",&t);
    while(t--)
    {
        memset(mem, -1, sizeof(mem));
        memset(mem2, -1, sizeof(mem2));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        j=0;
        for(int i=n-1;i>=0;i--)
        {
            b[j]=a[i];
            j++;
        }
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, lis(i)+lis2(i)-1);
        }
        printf("%d\n", mx);
    }
    return 0;
}
