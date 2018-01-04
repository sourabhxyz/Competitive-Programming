#include<bits/stdc++.h>

using namespace std;

#define INF 100000

map<string, int> data;
int mat[31][31];
int V;

void clearmat()
{
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < 31; j++)
        {
            if(i == j)
                mat[i][j] = 0;
            else mat[i][j] = INF;
        }
    }
}

void apsp()
{
    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++) {
                mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    cout << "SHIPPING ROUTES OUTPUT\n";
    for(int tc = 1; tc <= t; tc++)
    {
        clearmat();
        data.clear();
        int m, n, p;
        cin >> m >> n >> p;
        string s;
        int k = 0;
        for(int i = 0; i < m; i++) {
            cin >> s;
            if (data.find(s) == data.end())
            {
                data[s] = k++;
            }
        }
        V = k;
        for(int i = 0; i < n; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            mat[data[s1]][data[s2]] = 1;
            mat[data[s2]][data[s1]] = 1;
        }
        apsp();
        cout << "\nDATA SET  " << tc << "\n\n";
        for(int i = 0; i < p; i++)
        {
            int size;
            cin >> size;
            string s1, s2;
            cin >> s1 >> s2;
            if(mat[data[s1]][data[s2]] == INF)
            {
                cout << "NO SHIPMENT POSSIBLE\n";
            }
            else
            {
                cout << "$" << size * mat[data[s1]][data[s2]] * 100 << "\n";
            }
        }

    }
    cout << "\nEND OF OUTPUT\n";
}
