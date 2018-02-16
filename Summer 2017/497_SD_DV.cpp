/**It shows that the grid need not be square*/
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
#define INF 100000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)

vector<int> a;
vector<int> L;
int LisSequence[32000]; // for storing the sequence
int mem[33000];
int lis(int i)
{
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] < a[i])
        {
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
}
void findSequence( int maxLength ) { // finds a valid sequence
    int i, j; // variable used for iteration

    // at first find the position of the item whose L[] is maximum
    i = 0;
    for( j = 1; j < a.size(); j++ ) {
        if( L[j] > L[i] )
            i = j;
    }

    // initialize the position in LisSequence where the items can be added.
    // observe that the data are saving from right to left!
    int top = L[i] - 1;

    // insert the item in i-th position to LisSequence
    LisSequence[top] = a[i];
    top--; // is decreasing such that a new item can be added in a new place

    // now find the other valid numbers to form the sequence
    for( j = i - 1; j >= 0; j-- ) {
        if( a[j] < a[i] && L[j] == L[i] - 1 ) {
            // we have found a valid item so, we will save it
            i = j; // as in our algorithm
            LisSequence[top] = a[i]; // stored
            top--; // decreased for new items
        }
    }

    // so, we have got the sequence, now we want to print it
    for( i = 0; i < maxLength; i++ ) {
        cout<<LisSequence[i]<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    string line;
    int t;
    cin>>t;
    cin.ignore();
    getline(cin,line);
    while(t--)
    {
        memset(mem, -1, sizeof(mem));
        L.clear();
        a.clear();
        while(getline(cin,line)&&line!="")
        {
            stringstream strm;
            strm<<line;
            int temp;
            strm>>temp;
            a.push_back(temp);
        }
        int mx = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int temp = lis(i);
            L.push_back(temp);
            mx = max(mx, temp);
        }
        cout<<"Max hits: "<<mx<<"\n";
        findSequence(mx);
        if(t>0) cout<<'\n';
    }
	return 0;
}

