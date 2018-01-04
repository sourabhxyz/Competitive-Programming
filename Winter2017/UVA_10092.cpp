#include<bits/stdc++.h>

using namespace std;

#define INF 100000000
const int mv = 1025;
int nk, np;
int res[mv][mv];
vector<int> p;
int f;
vector<vector<int> > neig;

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
    while(cin >> nk >> np && (nk || np)) {
        for(int i = 0; i < mv; i++)
            for(int j = 0; j < mv; j++)
            {
                res[i][j] = 0;
            }
        neig.clear();
        neig.resize(nk + 1);
        vector<int> ncats;
        for(int i = 0; i < nk; i++)
        {
            int temp;
            cin >> temp;
            ncats.push_back(temp);
        }
        for(int i = nk + 1; i < nk + 1 + np; i++)
        {
            int l;
            cin >> l;
            for(int j = 0; j < l; j++)
            {
                int temp;
                cin >> temp;
                res[temp][i] = 1;
                neig[temp].push_back(i);
            }
        }
        int t = nk + 1 + np;
        for(int i = 1; i <= nk; i++)
        {
            res[0][i] = ncats[i - 1];
        }
        for(int i = 0; i < np; i++)
        {
           res[nk + 1 + i][t] = 1;
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
        bool done = true;
        for(int i = 1; i <= nk; i++)
        {
            if(res[0][i] != 0)
            {
                done = false;
                break;
            }
        }
        if(!done)
        {
            cout << "0\n";
            continue;
        }
        cout << "1\n";
        queue<int> q;
        for(int i = 1; i <= nk; i++)
        {
            q.push(i);
        }
        while(!q.empty())
        {
            int at = q.front(); q.pop();
            vector<int> ans;
            for(int i = 0; i < neig[at].size(); i++)
            {
                int to = neig[at][i];
                if(!res[at][to])
                {
                    ans.push_back(to);
                }
            }
            cout << ans[0] - nk;
            for(int i = 1; i < ans.size(); i++)
            {
                cout << " " << ans[i] - nk;
            }
            cout << "\n";
        }
    }
    return 0;
}
