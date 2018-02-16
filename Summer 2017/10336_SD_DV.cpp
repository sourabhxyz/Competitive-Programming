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
int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1}; ///only keeping N,S,E,W.
int floodfill(int r, int c, char c1, char c2)  // returns the size of CC
{
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1; // adds 1 to ans because vertex (r, c) has c1 as its color
    grid[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 4; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans; // the code is neat due to dr[] and dc[]
}
bool cmp(pair<char,int> a,pair<char,int> b)
{
    if(a.second!=b.second) return a.second>b.second;
    else return a.first<b.first;
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("ina");
    //FileOut("outa");
    int n,m,t,cnt,no=0;
    cin>>t;
    while(t--)
    {
        map<char,int> data_;
        vector<pair<char,int> > data;
        cin>>n>>m;
        no++;
        cnt = 0;
        R = n;
        C = m;
        cin.ignore();
        for(int i = 0;i<n;i++)
            getline(cin,grid[i]);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]!='.')
                {
                    data_[grid[i][j]]+=1;
                    floodfill(i,j,grid[i][j],'.');
                }
            }
        }
        for(map<char,int>::iterator it = data_.begin();it!=data_.end();it++)
        {
            data.push_back(make_pair(it->first,it->second));
        }
        sort(data.begin(),data.end(),cmp);
        cout<<"World #"<<no<<"\n";
        for(int i = 0;i<data.size();i++)
        {
            cout<<data[i].first<<": "<<data[i].second<<"\n";
        }
    }
    return 0;
}
