#include<bits/stdc++.h>

using namespace std;

#define INF 100000

int mat[200][200];
map<string, int> data;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n, r;
    for(int tc = 1; cin >> n >> r && (n || r); tc++)
    {
        data.clear();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j) mat[i][j] = INF;
                else mat[i][j] = 0;
            }
        }
        int k = 0;
        for(int i = 0; i < r; i++)
        {
            string a, b;
            int wt;
            cin >> a >> b >> wt;
            if(data.find(a) == data.end())
            {
                data[a] = k++;
            }
            if(data.find(b) == data.end())
            {
                data[b] = k++;
            }
            mat[data[a]][data[b]] = mat[data[b]][data[a]] = wt;
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
        string a, b;
        cin >> a >> b;
        cout << "Scenario #" << tc << "\n";
        cout << mat[data[a]][data[b]] << " tons";
        cout << "\n\n";

    }
    return 0;
}
