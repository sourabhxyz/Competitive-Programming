#include<bits/stdc++.h>

using namespace std;

#define INF 100000

int mat[200][200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n, r;
    for(int tc = 1; cin >> n >> r && (n || r); tc++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j) mat[i][j] = INF;
                else mat[i][j] = 0;
            }
        }
        for(int i = 0; i < r; i++)
        {
            int u, v, wt;
            cin >> u >> v >> wt;
            mat[u - 1][v - 1] = mat[v - 1][u - 1] = wt;
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(mat[i][j] == INF)
                    {
                        mat[i][j] = min(mat[i][k], mat[k][j]);
                    }
                    else
                        mat[i][j] = max(mat[i][j], min(mat[i][k], mat[k][j]));
                }
            }
        }
        int s, d, t;
        cin >> s >> d >> t;
        cout << "Scenario #" << tc << "\n";
        cout << "Minimum Number of Trips = " << ceil(double(t)/(mat[s - 1][d - 1] - 1));
        cout << "\n\n";

    }
    return 0;
}
