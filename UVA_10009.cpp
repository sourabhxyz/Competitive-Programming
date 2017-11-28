#include<bits/stdc++.h>

using namespace std;

map<string,int> data;
vector<string> md;
vector<char> tgp;
int g[1000][1000];
int path[1000][1000];
#define INF 100000

void getPath(int from, int to)
{
    if(to != from) getPath(path[to][from], to);
    cout << tgp[from];
}

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
        md.clear();
        tgp.clear();
        for(int i = 0; i < 1000; i++)
        {
            for(int j = 0; j < 1000; j++)
            {
                if(i != j) g[i][j] = INF;
                else g[i][j] = 0;
            }
        }
        int vert = 0;
        data.clear();
        int m, n;
        cin >> m >> n;
        for(int i = 0; i < m; i++)
        {
            string temp, temp2;
            cin >> temp;
            if(data.find(temp) == data.end())
            {
                data[temp] = vert++;
                md.push_back(temp);
                tgp.push_back(temp[0]);
            }
            cin >> temp2;
            if(data.find(temp2) == data.end())
            {
                data[temp2] = vert++;
                md.push_back(temp2);
                tgp.push_back(temp2[0]);
            }
            g[data[temp]][data[temp2]] = g[data[temp2]][data[temp]] = 1;
            path[data[temp]][data[temp2]] = data[temp];
            path[data[temp2]][data[temp]] = data[temp2];
        }
        for(int k = 0; k < vert; k++)
        {
            for(int i = 0; i < vert; i++)
            {
                for(int j = 0; j < vert; j++)
                {
                    if(g[i][j] > g[i][k] + g[k][j])
                    {
                        g[i][j] = g[i][k] + g[k][j];
                        path[i][j] = path[k][j];
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            string from, to;
            cin >> to >> from;
            getPath(data[from], data[to]);
            cout << "\n";
        }
        if(t > 0) cout << "\n";
    }
    return 0;
}
