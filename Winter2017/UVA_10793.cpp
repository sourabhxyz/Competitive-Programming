#include<bits/stdc++.h>

using namespace std;

#define INF 100000000

int mat[205][205];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int l, d;
        cin >> l >> d;
        for(int i = 0; i < l; i++)
        {
            for(int j = i + 1; j < l; j++)
            {
                mat[i][j] = mat[j][i] = INF;
            }
            mat[i][i] = 0;
        }
        for(int i = 0; i < d; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            mat[u - 1][v - 1] = mat[v - 1][u - 1] = min(mat[u- 1][v - 1], w);
        }
        for(int k = 0; k < l; k++)
        {
            for(int i = 0; i < l; i++)
            {
                for(int j = 0; j < l; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        vector<int> cand;
        for(int i = 5; i < l; i++)
        {
            if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][3] == mat[i][2] && mat[i][3] == mat[i][4])
            {
                cand.push_back(i);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < cand.size(); i++)
        {
            int max = -1;
            for(int j = 0; j < l; j++)
            {
                if(mat[cand[i]][j] > max)
                {
                    max = mat[cand[i]][j];
                }
            }
            ans = min(ans, max);
        }
        cout << "Map " << tc << ": "; ans >= INF ? cout << "-1\n" : cout << ans << "\n";
    }
    return 0;
}
