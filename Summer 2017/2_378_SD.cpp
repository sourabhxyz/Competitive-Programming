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
typedef complex<double> point;
#define X real()
#define Y imag()
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
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define EPS 1e-7
int main() {
   // FileIn("in");
   // FileOut("out");
    ll x1,x2,y1,y2,a1,b1,c1,a2,b2,c2,d,dx,dy;
    int n;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--)
    {
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        a1=y2-y1;
        b1=x1-x2;
        c1=a1*x1+b1*y1;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        a2=y2-y1;
        b2=x1-x2;
        c2=a2*x1+b2*y1;
        d=a1*b2-a2*b1;
        if(abs(d)==0)//i.e. they are parallel
        {
            if(b1==0&&b2==0)// if both are perpendicular...
            {
                if(c1==c2)
                {
                    printf("LINE\n");
                    continue;
                }
                else
                {
                    printf("NONE\n");
                    continue;
                }
            }
            if(c1*b2==c2*b1)//if their y intercepts are equal...
            {
                printf("LINE\n");
                continue;
            }
            else
            {
                printf("NONE\n");
                continue;
            }
        }
        dx=b2*c1-b1*c2;
        dy=a1*c2-a2*c1;
        printf("POINT %0.2f %0.2f\n",double(dx)/d,double(dy)/d);
    }
    printf("END OF OUTPUT\n");
    return 0;
}

/*#include<bits/stdc++.h>
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
typedef complex<double> point;
#define X real()
#define Y imag()
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
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define EPS 1e-7
int main() {
    //FileIn("in");
    //FileOut("out");
    double x1,x2,y1,y2,a1,b1,c1,a2,b2,c2,d,ansx,ansy;
    int n;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--)
    {
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        a1=y2-y1;
        b1=x1-x2;
        c1=a1*x1+b1*y1;
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        a2=y2-y1;
        b2=x1-x2;
        c2=a2*x1+b2*y1;
        d=a1*b2-a2*b1;
        if(abs(d)<EPS)//i.e. they are parallel
        {
            if(b1==0&&b2==0)// if both are perpendicular...
            {
                if(c1==c2)
                {
                    printf("LINE\n");
                    continue;
                }
                else
                {
                    printf("NONE\n");
                    continue;
                }
            }
            if(abs(c1/b1-c2/b2)<EPS)//if their y intercepts are equal...
            {
                printf("LINE\n");
                continue;
            }
            else
            {
                printf("NONE\n");
                continue;
            }
        }
        ansx=(b2*c1-b1*c2)/d;
        ansy=(a1*c2-a2*c1)/d;*/
        /*if(abs(ansx)<EPS)
            ansx=0;
        if(abs(ansy)<EPS)
            ansy=0;*/
        /*printf("POINT %0.2f %0.2f\n",ansx,ansy);
    }
    printf("END OF OUTPUT\n");
    return 0;
}*/
