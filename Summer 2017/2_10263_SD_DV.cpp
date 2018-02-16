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
bool segment = true;

double dot(P(a), P(b))
{
    return real(a) * real(b) + imag(a) * imag(b);
}
double angle(P(a), P(b), P(c))
{
    return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b));
}
point closest_point(L(a, b), P(c))
{
    if (segment)
    {
        if (dot(b - a, c - b) > 0) return b;
        if (dot(a - b, c - a) > 0) return a;
    }
    double t = dot(c - a, b - a) / norm(b - a);
    return a + t * (b - a);
}
double cross(P(a), P(b)) {
return real(a)*imag(b) - imag(a)*real(b);
}
bool isout(L(a, b), P(c))
{
    if (dot(b - a, c - b) > 0) return true;
    if (dot(a - b, c - a) > 0) return true;
    return false;
}
int main() {
    //FileIn("in");
    //FileOut("out");
    point m,a,b,ans,res;
    double mx,my,dis,mini;
    int n;
    while(scanf("%lf%lf",&mx,&my)==2)
    {
        mini=10000;
        m.real(mx);
        m.imag(my);
        scanf("%d %lf %lf",&n,&mx,&my);
        b.real(mx);
        b.imag(my);
        while(n--)
        {
            a=b;
            scanf("%lf %lf",&mx,&my);
            b.real(mx);
            b.imag(my);
            if(isout(a,b,m))
            {
                dis=min(abs(b-m),abs(m-a));
            }
            else dis=cross(a-m,b-m)/abs(b-a);
            dis=abs(dis);
            if(dis+1e-7<mini)
            {
                mini=dis;
                ans=closest_point(a,b,m);
            }
        }
        printf("%0.4f\n%0.4f\n",ans.X,ans.Y);
    }
    return 0;
}

/*int main()
{
    int n;
	double mx,my;
	bool check;
	double a,b,c,ansx,ansy,d,minimum,tempx,tempy,d1,d2;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while(scanf("%lf %lf",&mx,&my)==2)
    {
        minimum=100000;
        scanf("%d",&n);
        double x[n+1],y[n+1];
        for(int i=0;i<=n;i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
        }
        for(int i=0;i<n;i++)
        {
            a=y[i+1]-y[i];
            b=x[i]-x[i+1];
            c=(x[i+1]-x[i])*y[i]-(y[i+1]-y[i])*x[i];
            d=(a*mx+b*my+c)/sqrt((pow(a,2)+pow(b,2)));
            if(d<0)
                d*=-1;
            tempx=(b*(b*mx-a*my)-a*c)/(pow(a,2)+pow(b,2));
            tempy=(a*(-b*mx+a*my)-b*c)/(pow(a,2)+pow(b,2));
            if(d<0.00001&&d>-0.00001)
            {
                d1=sqrt((pow((x[i]-mx),2)+pow((y[i]-my),2)));
                d2=sqrt((pow((x[i+1]-mx),2)+pow((y[i+1]-my),2)));
                if(d1<d2)
                {
                        tempx=x[i];
                        tempy=y[i];
                        d=d1;
                }
                else
                {
                    d=d2;
                    tempx=x[i+1];
                    tempy=y[i+1];
                }
            }
            else if((tempx>x[i]+0.001&&tempx>x[i+1]+0.001)||(tempx<x[i]+0.001&&tempx<x[i+1]+0.001)&&((tempy>y[i]+0.001&&tempy>y[i+1]+0.001)||(tempy<y[i]+0.001&&tempy<y[i+1]+0.001)))
            {
                d1=sqrt((pow((x[i]-mx),2)+pow((y[i]-my),2)));
                d2=sqrt((pow((x[i+1]-mx),2)+pow((y[i+1]-my),2)));
                if(d1<d2)
                {
                        d=d1;
                        tempx=x[i];
                        tempy=y[i];
                }
                else
                {
                    d=d2;
                    tempx=x[i+1];
                    tempy=y[i+1];
                }
            }
            if(d<minimum)
            {
                minimum=d;
                ansx=tempx;
                //ansx=round(ansx*10000)/10000;
                ansy=tempy;
                //ansy=round(ansy*10000)/10000;
            }
        }
        printf("%0.4f\n%0.4f\n",ansx,ansy);
    }
    return 0;
}*/
