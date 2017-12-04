#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
int r, c;

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
        cin >> r >> c;
        int mat[r][c];
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) mat[i][j] = 0;
        cin.ignore();
        for(int i = 0; i < r; i++)
        {
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;
            int ri;
            ss >> ri;
            int ci;
            while(ss >> ci)
            {
                mat[ri - 1][ci - 1] = -1;
            }
        }
        if(mat[0][0] == -1 || mat[r - 1][c - 1] == -1)
        {
            cout << "0\n";
            continue;
        }
        mat[0][0] = 1;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j] == -1) continue;
                if(i < r - 1 && mat[i + 1][j] != -1) {
                    mat[i + 1][j] += mat[i][j];
                }
                if(j < c - 1 && mat[i][j + 1] != -1) {
                    mat[i][j + 1] += mat[i][j];
                }
            }
        }
        cout << mat[r - 1][c - 1] << "\n";
        if(t > 0) cout << '\n';
    }
    return 0;
}
