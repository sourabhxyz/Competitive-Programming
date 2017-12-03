#include<bits/stdc++.h>

using namespace std;

#define INF 100000000
#define EPS 1e-8
int n, m, s, t, f;
const int mv = 205;
int res[mv][mv];
vector<int> p;

void augment(int at, int minedge)
{
    if(at == s) {
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
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int l;
    cin >> l;
    for(int tc = 1; tc <= l; tc++)
    {
        for(int i = 0; i < mv; i++)
        {
            for(int j = 0; j < mv; j++)
            {
                res[i][j] = 0;
            }
        }
        cin >> n;
        vector<int> seta, setb;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            seta.push_back(temp);
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            setb.push_back(temp);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(setb[j] == 0 || (seta[i] != 0 && setb[j] % seta[i] == 0))
                {
                    res[i][j + n] = 1;
                }
            }
        }
        s = n + m;
        t = s + 1;
        for(int i = 0; i < n; i++)
        {
            res[s][i] = 1;
        }
        for(int i = n; i < s; i++)
        {
            res[i][t] = 1;
        }
        int mf = 0;
        while(true)
        {
            f = 0;
            p.assign(t + 1, -1);
            queue<int> q;
            q.push(s);
            vector<bool> visited(t + 1, false);
            visited[s] = true;
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
        cout << "Case " << tc << ": " << mf << '\n';
    }
}
