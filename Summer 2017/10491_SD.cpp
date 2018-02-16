/**The first step is to realize that there are two ways to get a car. Either you pick a cow
first and then switch to a car, or you pick a car first, and then switch to another car.
The probability of each case can be computed as shown below.
In the first case, the chance of picking a cow first is (NCOWS / (NCOWS+NCARS)).
Then, the chance of switching to a car is (NCARS / (NCARS+NCOWS-NSHOW-1)).
Multiply these two values together to get the probability of the first case. The -1 is to
account for the door that you have already chosen, as you cannot switch to it.
The probability of the second case can be computed in a similar manner. The chance
of picking a car first is (NCARS / (NCARS+NCOWS)). Then, the chance of switching
to a car is ((NCARS-1) / (NCARS+NCOWS-NSHOW-1)). Both -1 accounts for the
car that you have already chosen.
Sum the probability values of these two cases together to get the final answer.**/
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

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    double ncow,ncar,nshow;
    while(cin>>ncow>>ncar>>nshow)
    {
        cout<<fixed<<setprecision(5)<<ncow/(ncow+ncar)*ncar/(ncar+ncow-nshow-1)+ncar/(ncar+ncow)*(ncar-1)/(ncar+ncow-nshow-1)<<"\n";
    }
    return 0;
}

