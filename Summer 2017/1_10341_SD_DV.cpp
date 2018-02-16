/*The problem asks for the root of an equation. Since f is a non-increasing function on [0,1], 
as f' < 0 .
it is sufficient to check the signs for f(0) and f(1) to determine whether there is a root in range [0,1]. There are at least three ways to find a root:
The simplest is the Bisection method. 
Note: Time complexity of binary search is log(n)*/

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
double p,q,r,s,t,u,EPS = 1e-7;//although i could have defined p,q,r,s,t,u as int...
double f(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
bool test(double x)
{
    return f(x) <= 0.0;
}
int main() {
    //FileIn("in");
    //FileOut("out");
    double lo,hi,mid;
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6)
    {
        if(f(0)*f(1)>0)
        {
            printf("No solution\n");
            continue;
        }
        lo = 0.0;
        hi = 1.0;
        while (hi - lo > EPS)
        {
            mid = (lo + hi) / 2.0;
            if (test(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        printf("%0.4f\n", lo);
    }
    return 0;
}

