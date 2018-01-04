#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int sx, sy, ex, ey;
        cin >> sy >> sx >> ey >> ex;
        sx--; sy--; ex--; ey--;
        int w;
        cin >> w;
        long long int mat[n][n];
        bool can[n * n + n][n * n + n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                mat[i][j] = 0;
            }
        for(int i = 0; i < n * n + n; i++)
        {
            for(int j = 0; j < n * n + n; j++)
            {
                can[i][j] = true;
            }
        }
        for(int i = 0; i < w; i++)
        {
            int x, y;
            cin >> y >> x;
            x--; y--;
            int at = x * n + y;
            char d;
            cin >> d;
            if(d == 'S')
            {
                int nr = x - 1;
                int nc = y;
                int to = nr * n + nc;
                can[at][to] = can[to][at] = false;
            }
            if(d == 'N')
            {
                int nr = x + 1;
                int nc = y;
                int to = nr * n + nc;
                can[at][to] = can[to][at] = false;
            }
            if(d == 'E')
            {
                int nr = x;
                int nc = y + 1;
                int to = nr * n + nc;
                can[at][to] = can[to][at] = false;
            }
            if(d == 'W')
            {
                int nr = x;
                int nc = y - 1;
                int to = nr * n + nc;
                can[at][to] = can[to][at] = false;
            }
        }
        mat[sx][sy] = 1;
        for(int i = sx; i < n; i++)
        {
            for(int j = sy; j < n; j++)
            {
                if(i < n - 1 && can[i * n + j][(i + 1) * n + j])
                {
                    mat[i + 1][j] += mat[i][j];
                }
                if(j < n - 1 && can[i * n + j][i * n + j + 1])
                {
                    mat[i][j + 1] += mat[i][j];
                }
            }
        }
        cout << mat[ex][ey] << "\n";
    }
    return 0;
}
