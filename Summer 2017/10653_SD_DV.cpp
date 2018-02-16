#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
#define INF 10000000
using namespace std;
 
int matrix [1000 + 5] [1000 + 5];
int R, C;
queue <int> q;
 
void reset ()
{
    for ( int i = 0; i < 1005; i++ )
        memset (matrix [i], -1, sizeof (matrix [i]));
}
 
bool valid (int r, int c)
{
    if ( r >= 0 && r <= R && c >= 0 && c <= C ) return true;
    return false;
}
 
void insert (int r, int c, int val)
{
    matrix [r] [c] = val + 1;
    q.push (r);
    q.push (c);
}
 
int main ()
{
    while ( scanf ("%d %d", &R, &C) ) {
        if ( R == 0 && C == 0 ) break;
 
        reset ();
 
        int r;
        scanf ("%d", &r);
 
        for ( int i = 0; i < r; i++ ) {
            int rowNumber;
            scanf ("%d", &rowNumber);
 
            int mines;
            scanf ("%d", &mines);
 
            for ( int j = 0; j < mines; j++ ) {
                int pos;
                scanf ("%d", &pos);
                matrix [rowNumber] [pos] = INF;
            }
        }
 
        int sourceR, sourceC, destR, destC;
        scanf ("%d %d %d %d", &sourceR, &sourceC, &destR, &destC);
 
        matrix [sourceR] [sourceC] = 0;
        q.push (sourceR);
        q.push (sourceC);
 
        while ( !q.empty() ) {
            int row, col;
            row = q.front (); q.pop ();
            col = q.front (); q.pop ();
 
            if ( valid (row - 1, col ) && matrix [row - 1] [col] < 0 )
                    insert (row - 1, col, matrix [row] [col]);
            if ( valid (row, col + 1) && matrix [row] [col + 1] < 0 )
                    insert (row, col + 1, matrix [row] [col]);
            if ( valid (row + 1, col) && matrix [row + 1] [col] < 0 )
                    insert (row + 1, col, matrix [row] [col]);
            if ( valid (row, col - 1) && matrix [row] [col - 1] < 0 )
                    insert (row, col - 1, matrix [row] [col]);
        }
 
        printf ("%d\n", matrix [destR] [destC]);
    }
 
    return 0;
}
