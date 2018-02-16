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
#define EPS 1e-8
int dr[] = {1,1,0,-1,-1,-1, 0, 1}; // trick to explore an implicit 2D grid
int dc[] = {0,1,1, 1, 0,-1,-1,-1}; // S,SE,E,NE,N,NW,W,SW neighbors
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    bool first = true;
    int t;
    cin>>t;
    while(t--)
    {
        if(first) first = false;
        else cout<<'\n';
        int r,c;
        cin>>r>>c;
        string line[r];
        cin.ignore();
        for(int i = 0;i<r;i++)
        {
            getline(cin,line[i]);
            transform(line[i].begin(),line[i].end(),line[i].begin(),::tolower);
        }
        int n;
        cin>>n;
        string word;
        for(int i = 0;i<n;i++)
        {
            cin>>word;
            transform(word.begin(),word.end(),word.begin(),::tolower);
            for(int r_ = 0;r_<r;r_++)
            {
                for(int c_ = 0;c_<c;c_++)
                {
                    if(line[r_][c_] == word[0])
                    {
                        for(int d = 0;d<8;d++)
                        {
                            int x = r_;
                            int y = c_;
                            int cnt = 0;
                            while(line[x][y]==word[cnt])
                            {
                                cnt++;
                                if(cnt==word.size())
                                {
                                    cout<<r_+1<<" "<<c_+1<<"\n";
                                    r_ = r;
                                    c_ = c;
                                    d = 8;
                                    break;
                                }
                                x+=dr[d];
                                y+=dc[d];
                                if(x < 0 || y < 0 || x >= r || y >= c)
                                    break;
                            }

                        }
                    }
                }
            }
        }
    }
    return 0;
}

