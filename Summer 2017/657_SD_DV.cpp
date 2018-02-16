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
int R,C,cnt;
string grid[55];
int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1}; ///only keeping N,S,E,W.
void floodfill2(int r,int c)
{
    if (r < 0 || r >= R || c < 0 || c >= C||grid[r][c]!='X') return;
    grid[r][c]='*'; ///we cant assign it period.
    for (int d = 0; d < 4; d++)
        floodfill2(r + dr[d], c + dc[d]);
}
void floodfill(int r, int c)
{
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (grid[r][c]=='.') return;
    if(grid[r][c]=='X')
    {
        cnt++;
        floodfill2(r,c);
    }
    grid[r][c] = '.';
    for (int d = 0; d < 4; d++) ///notice d<4 and not <8.
        floodfill(r + dr[d], c + dc[d]);
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    string temp;
    vi ans;
    int cases=0;
    while(cin>>C>>R&&(C||R))
    {
        cases++;
        ans.clear();
        temp.clear();
        cin.ignore();
        for(int i=0;i<R;i++)
            getline(cin,grid[i]);
        for(int i=0;i<C;i++)
            temp.push_back('.');
        for(int i=0;i<R;i++)
        {
            if(grid[i]==temp)
                continue;
            else
            {
                for(int j=0;j<C;j++)
                {
                    if(grid[i][j]!='.')
                    {
                        cnt=0;
                        floodfill(i,j);
                        ans.push_back(cnt);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<"Throw "<<cases<<"\n";
        if(ans.size()>0)
            cout<<ans[0];
        for(int i=1;i<ans.size();i++)
            cout<<" "<<ans[i];
        cout<<"\n\n";
    }
    return 0;
}
