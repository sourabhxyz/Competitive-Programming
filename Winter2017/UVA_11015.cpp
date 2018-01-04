#include<bits/stdc++.h>

using namespace std;

#define INF 100000

int mat[200][200];
vector<string> data;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n, m, tc = 0;
    while(cin >> n >> m && (n || m))
    {
        data.clear();
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            string line;
            cin >> line;
            data.push_back(line);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j) mat[i][j] = INF;
                else mat[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            mat[u - 1][v - 1] = mat[v - 1][u - 1] = w;
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int min = INT_MAX;
        int mark;
        for(int i = 0; i < n; i++)
        {
            int check = 0;
            for(int j = 0; j < n; j++)
            {
                check += mat[i][j];
            }
            if(min > check)
            {
                min = check;
                mark = i;
            }
        }
        cout << "Case #" << ++tc << " : " << data[mark] << "\n";
    }
    return 0;
}
