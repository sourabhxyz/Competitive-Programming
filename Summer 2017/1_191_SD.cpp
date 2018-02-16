/*First, check whether or not either of the inputs lies inside the rectangle. If so, output "T".
Next see, whether we have a line or a point.
Next, calculate the cross product of the line segment with each corner of the rectangle. If the 
sign of each cross product is the same (i.e. all positive or all negative) then output "F", as the 
rectangle is entirely on one side of the line.
If you reach this point, then we know that the line that the line segment desribes goes through the 
rectangle, but we need to determine if just the line segment does. 
Determine the shadow of the rectangle and the line segment against the X and Y-axes. 
If the shadows overlap on both axes, output "T". Otherwise, output "F".
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
bool yes=true;
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
bool cross(P(a), P(b))
{
    double temp;
    temp= real(a)*imag(b) - imag(a)*real(b);
    if(temp==0)
    {
        yes=true;
        return true;
    }
    else if(temp>0)
        return true;
    else
        return false;
    //temp>0?return true: return false;
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
    point a,b,sqa,sqb,sqc,sqd;
    double ax,ay,bx,by,sqx1,sqx2,sqy1,sqy2;
    int n;
    bool arr[4];
    scanf("%d",&n);
    while(n--)
    {
        yes=false;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&sqx1,&sqy1,&sqx2,&sqy2);
        a.real(ax),a.imag(ay),b.real(bx),b.imag(by);
        sqa.real(sqx1),sqa.imag(sqy1),sqc.real(sqx2),sqc.imag(sqy2);
        sqb.real(sqx2),sqb.imag(sqy1),sqd.real(sqx1),sqd.imag(sqy2);
        if(((a.X>=min(sqa.X,sqc.X)&&a.X<=max(sqc.X,sqa.X))&&(a.Y<=max(sqa.Y,sqc.Y)&&a.Y>=min(sqa.Y,sqc.Y)))||((b.X>=min(sqa.X,sqc.X)&&b.X<=max(sqc.X,sqa.X))&&(b.Y<=max(sqa.Y,sqc.Y)&&b.Y>=min(sqa.Y,sqc.Y))))
        {
            printf("T\n");
            continue;
        }
        if(a==b)
        {
            printf("F\n");
            continue;
        }
        arr[0]=cross(b-a,sqa-a);
        arr[1]=cross(b-a,sqb-a);
        arr[2]=cross(b-a,sqc-a);
        arr[3]=cross(b-a,sqd-a);
        if(((arr[0]==true&&arr[1]==true&&arr[2]==true&&arr[3]==true)||(arr[0]==false&&arr[1]==false&&arr[2]==false&&arr[3]==false))&&!yes)
            printf("F\n");
        else if((min(ax,bx)<=min(sqx1,sqx2)&&max(ax,bx)>=min(sqx1,sqx2))||(min(ax,bx)<=max(sqx1,sqx2)&&max(ax,bx)>=max(sqx1,sqx2))||(min(ax,bx)>=min(sqx1,sqx2)&&max(ax,bx)<=max(sqx1,sqx2)))
        {
            if((min(ay,by)<=min(sqy1,sqy2)&&max(ay,by)>=min(sqy1,sqy2))||(min(ay,by)<=max(sqy1,sqy2)&&max(ay,by)>=max(sqy1,sqy2))||(min(ay,by)>=min(sqy1,sqy2)&&max(ay,by)<=max(sqy1,sqy2)))
                printf("T\n");
            else
                printf("F\n");
        }
        else
            printf("F\n");
    }
    return 0;
}

