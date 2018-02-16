/*Note: its not neccesseary that we'll be only dealing with chars, we could have been given ints, double
etc. so modify the floodfill algo accordingly. */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string, int> msi;
typedef map<int,pair<int,int> > miii;
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 50000000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1
int R,C;
string grid[100];
int dr[] = {1,1,0,-1,-1,-1, 0, 1}; // trick to explore an implicit 2D grid
int dc[] = {0,1,1, 1, 0,-1,-1,-1}; // S,SE,E,NE,N,NW,W,SW neighbors
int floodfill(int r, int c, char c1, char c2)  // returns the size of CC
{
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1; // adds 1 to ans because vertex (r, c) has c1 as its color
    grid[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans; // the code is neat due to dr[] and dc[]
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int t,i,x,y;
    cin>>t;
    string line;
    cin.ignore();
    getline(cin,line);//reads the first blank line
    while(t--)
    {
        for(i=0;getline(cin,grid[i])&&grid[i][0]>65;i++);//for(int i=0;scanf("%s",grid[i])&&grid[i][0]>65;i++);
        R=i;
        C=grid[0].size();
        stringstream strm2;
        strm2<<grid[i];
        strm2>>x>>y;
        cout<<floodfill(x-1, y-1, 'W', '.')<<"\n";//printf("%d\n", floodfill(x, y, 'W', '.'));
        floodfill(x-1,y-1,'.','W');
        while(getline(cin,line)&&line!="")
        {
            stringstream strm;
            strm<<line;
            strm>>x>>y;
            cout<<floodfill(x-1, y-1, 'W', '.')<<"\n";
            floodfill(x-1,y-1,'.','W');
        }
        if(t!=0)
        cout<<"\n";
    }
    return 0;
}
