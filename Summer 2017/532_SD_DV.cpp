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
#define INF 5000000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1
using namespace std;

int matrix [35] [35][35];
int R, C,H;
queue <int> q;

void reset ()
{
        memset (matrix, -1, sizeof matrix);
}

bool valid (int r, int c,int h)
{
    if ( r >= 0 && r <= R && c >= 0 && c <= C&&h >= 0 && h <= H ) return true;
    return false;
}

void insert (int r, int c, int h,int val)
{
    matrix [r][c][h] = val + 1;
    q.push (r);
    q.push (c);
    q.push(h);
}

int main ()
{
    //FileIn("in");
    //FileOut("out");
    char ch;
    int sourceR, sourceC,sourceH, destR, destC,destH;
    while (cin>>H>>R>>C&&(H||R||C))
    {
        for(int h=0;h<H;h++)
        {
            for(int r=0;r<R;r++)
            {
                for(int c=0;c<C;c++)
                {
                    cin>>ch;
                    if(ch=='#')
                        matrix[r][c][h]=INF;
                    else if(ch=='.')
                        matrix[r][c][h]=-1;
                    else if(ch=='S')
                        sourceR=r,sourceC=c,sourceH=h,matrix[r][c][h]=0;
                    else if(ch=='E')
                        destC=c,destH=h,destR=r,matrix[r][c][h]=-1;
                }
            }
        }
        q.push (sourceR);
        q.push (sourceC);
        q.push(sourceH);
        while ( !q.empty() ) {
            int row, col,hi;
            row = q.front (); q.pop ();
            col = q.front (); q.pop ();
            hi=q.front();q.pop();
            if ( valid (row - 1, col, hi ) && matrix [row - 1] [col][hi] < 0 )
                    insert (row - 1, col, hi,matrix [row] [col][hi]);
            if ( valid (row, col + 1,hi) && matrix [row] [col + 1][hi] < 0 )
                    insert (row, col + 1,hi, matrix [row] [col][hi]);
            if ( valid (row + 1, col,hi) && matrix [row + 1] [col][hi] < 0 )
                    insert (row + 1, col,hi, matrix [row] [col][hi]);
            if ( valid (row, col - 1,hi) && matrix [row] [col - 1][hi] < 0 )
                    insert (row, col - 1,hi, matrix [row] [col][hi]);
            if ( valid (row, col,hi+1) && matrix [row] [col][hi+1] < 0 )
                    insert (row, col,hi+1, matrix [row] [col][hi]);
            if ( valid (row, col,hi-1) && matrix [row] [col][hi-1] < 0 )
                    insert (row, col,hi-1, matrix [row] [col][hi]);
        }
        matrix[destR][destC][destH]<0?cout<<"Trapped!\n" : cout<<"Escaped in "<<matrix[destR][destC][destH]<<" minute(s).\n";

    }
    return 0;
}
