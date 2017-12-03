#include<bits/stdc++.h>

using namespace std;

#define INF 100000000

int n, m;
map<string,int> mp;
int res[40][40];
vector<int> p;
int f;

void augment(int at, int minedge)
{
    if(at == 0) {
        f = minedge; return;
    }
    else if(p[at] != -1)
    {
        augment(p[at], min(minedge, res[p[at]][at]));
        res[p[at]][at] -= f;
        res[at][p[at]] += f;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    mp["XXL"] = 1;
    mp["XL"] = 2;
    mp["L"] = 3;
    mp["M"] = 4;
    mp["S"] = 5;
    mp["XS"] = 6;
    while(t--)
    {
        cin >> n >> m;
        int st = n / 6;
        for(int i = 0; i < 40; i++)
            for(int j = 0; j < 40; j++)
            {
                res[i][j] = 0;
            }
        int t = m + 7;
        for(int i = 0; i < m; i++)
        {
            string a, b;
            cin >> a >> b;
            res[mp[a]][i + 7] = 1;
            res[mp[b]][i + 7] = 1;
            res[i + 7][mp[b]] = 1;
            res[i + 7][mp[a]] = 1;
            res[i + 7][t] = 1;
            res[t][i + 7] = 1;
        }
        for(int i = 1; i <= 6; i++)
        {
            res[0][i] = st;
            res[i][0] = st;
        }
        int mf = 0;
        while(true)
        {
            f = 0;
            p.assign(t + 1, -1);
            queue<int> q;
            q.push(0);
            vector<bool> visited(t + 1, false);
            visited[0] = true;
            while(!q.empty())
            {
                int at = q.front(); q.pop();
                if(at == t) break;
                for(int i = 0; i <= t; i++)
                {
                    if(!visited[i] && res[at][i] > 0)
                    {
                        q.push(i);
                        visited[i] = true;
                        p[i] = at;
                    }
                }
            }
            augment(t, INF);
            if(f == 0) break;
            mf += f;
        }
        if(mf == m) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
