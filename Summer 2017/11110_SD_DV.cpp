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
int N;
int grid[100][100];
int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1}; ///only keeping N,S,E,W.
int floodfill(int r, int c, int c1, int c2)  // returns the size of CC
{
    if (r < 0 || r >= N || c < 0 || c >= N) return 0; // outside grid
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1; // adds 1 to ans because vertex (r, c) has c1 as its color
    grid[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 4; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans; // the code is neat due to dr[] and dc[]
}
bool visited[105];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int x,y,temp,cnt,equipartcheck;
    string data;
    char c;
    bool flag,ans;
    while(cin>>N&&N)
    {
        if(N==1)
        {
            cout<<"good\n";
            continue;
        }
        flag=true;
        ans=true;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                grid[i][j]=N;
        memset(visited,0,sizeof visited);
        cin.ignore();
        //memset(grid,N+48,sizeof grid);
        for(int k=0;k<N-1;k++)
        {
                getline(cin,data);
                stringstream strm2;
                strm2<<data;
                while(strm2>>x>>y)
                grid[x-1][y-1]=k+1;
        }
        for(int i=0;i<N&&flag;i++)
        {
            for(int j=0;j<N&&flag;j++)
            {
                if(grid[i][j]!=0)
                {
                    stringstream strm;
                    strm<<grid[i][j];
                    strm>>temp;
                    if(!visited[temp])
                    {
                        visited[temp]=true;
                        equipartcheck=floodfill(i,j,grid[i][j],0);
                        if(equipartcheck!=N)
                            flag=false;
                    }
                }
            }
        }
        for(int i=0;i<N&&ans&&flag;i++)
        {
            for(int j = 0 ; j<N && ans&&flag; j++)
            {
                if(grid[i][j]!=0)
                    ans=false;
            }
        }

        if(flag&&ans)
            cout<<"good\n";
        else
            cout<<"wrong\n";
    }
    return 0;
}
