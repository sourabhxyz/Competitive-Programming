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
typedef map<int,pair<int,int> > miii;
typedef complex<double> point;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<vi > vvi;
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
#define VISITED 1
#define UNVISITED -1
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define EPS 1e-9

double dot(P(a), P(b)) {
    return real(a) * real(b) + imag(a) * imag(b);
}
double angle(P(a), P(o), P(b)) {//gives the angle between vectors oa and ob.
    return acos(dot(a-o, b-o) / abs(a-o) / abs(b-o));
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
bool ccw(P(a),P(b),P(c)) //returns true if the point c is on left side of line ab
{
    return cross(c-a,c-b)>0? true: false;
}
bool collinear(P(a),P(b),P(c))//tells if the points are collinear...
{
    return abs(cross(c-a,c-b))<EPS? true: false;
}
double area(const vector<point> &pol) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)pol.size()-1; i++) {
        x1 = pol[i].X; x2 = pol[i+1].X;
        y1 = pol[i].Y; y2 = pol[i+1].Y;
        result += (x1 * y2 - x2 * y1);
    }
    return abs(result) / 2.0;
}
point pivot;//global declaration...
bool angleCmp(point a, point b) { // angle-sorting function
    if (collinear(pivot, a, b)) // special case
        return abs(a-pivot)< abs(b-pivot); // check which one is closer
    double d1x = a.X - pivot.X, d1y = a. Y- pivot.Y;
    double d2x = b.X - pivot.X, d2y = b.Y - pivot.Y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; // compare two angles
}
vector<point> CH(vector<point> P) { // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P;  // special case, the CH is P itself
    }
    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].Y < P[P0].Y || (P[i].Y == P[P0].Y && P[i].X > P[P0].X))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
    // second, sort points by angle w.r.t. pivot P0
    pivot = P[0]; // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
    // third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
    i = 2; // then, we check the rest
    while (i < n) { // note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
        else S.pop_back();  // or pop the top of S until we have a left turn
    }
    return S;  // return the result
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n,cnt=0;
    while(cin>>n&&n)
    {
        cnt++;
        vector<point> pol;
        for(int i = 0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            pol.push_back(point(x,y));
        }
        pol.push_back(pol[0]);
        double iarea = area(pol);
        vector<point> ch = CH(pol);
        double farea = area(ch);
        cout<<"Tile #"<<cnt<<"\n";
        cout<<"Wasted Space = ";
        cout<<fixed<<setprecision(2)<<(100.00*(farea-iarea)/farea)<<" %\n\n";
    }
    return 0;
}

