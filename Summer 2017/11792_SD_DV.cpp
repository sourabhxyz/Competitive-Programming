#include<bits/stdc++.h>

using namespace std;

vector<vector<int > > glist;
vector<int> cnt, imp;
int dist[10005][10005];

void bfs(int from)
{
    queue<int> q;
    q.push(from);
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i];
            if(dist[from][to] == 100000) {
                dist[from][to] = dist[from][at] + 1;
                //dist[to][from] = dist[from][to];
                q.push(to);
            }
        }
    }
}

int main()
{
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
    {
        int N, S;
        cin >> N >> S;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(i != j) dist[i][j] = 100000;
                else dist[i][j] = 0;
            }
        }
        cnt.clear();
        cnt.assign(N, 0);
        glist.clear();
        glist.resize(N);
        imp.clear();
        for(int i = 0; i < S; i++)
        {
            int prev;
            int now;
            cin >> prev;
            cnt[prev - 1]++;
            while(cin >> now && now != 0)
            {
                glist[prev - 1].push_back(now - 1);
                glist[now - 1].push_back(prev - 1);
                prev = now;
                cnt[now - 1]++;
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(cnt[i] > 1) imp.push_back(i);
        }
        int min = INT_MAX;
        int mark;
        int sum = 0;
        for(int i = 0; i < imp.size(); i++)
        {
            sum = 0;
            bfs(imp[i]);
            for(int j = 0; j < imp.size(); j++)
            {
                sum += dist[imp[i]][imp[j]];
            }
            if(min > sum)
            {
                min = sum;
                mark = imp[i];
            }
        }
        cout << "Krochanska is in: " << mark + 1 << "\n";
    }
    return 0;
}
