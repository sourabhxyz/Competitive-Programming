#include<bits/stdc++.h>

using namespace std;

#define INF 100000000

typedef pair<int, int> ii;
vector<vector<pair<int, int > > > g;
int f, inter;
vector<int> fi;
int fire[505];
vector<int> odist;

int dijkstra()
{
    priority_queue<ii, vector<ii>, greater<ii > > pq;
    odist.assign(10 * inter, INF);
    for(int i = 0; i < fi.size(); i++)
    {
        pq.push(ii(0, fi[i]));
        odist[fi[i]] = 0;
    }
    while(!pq.empty())
    {
        int di = pq.top().first; int at = pq.top().second; pq.pop();
        if(di == odist[at])
        {
            for(int i = 0; i < g[at].size(); i++)
            {
                int to = g[at][i].first;
                int w = g[at][i].second;
                if(odist[at] + w < odist[to])
                {
                    odist[to] = odist[at] + w;
                    pq.push(make_pair(odist[to], to));
                }
            }
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < inter; i++)
    {
        if(odist[i] > max)
        {
            max = odist[i];
        }
    }
    return max;
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
        cin >> f >> inter;
        memset(fire, false, sizeof(fire));
        fi.clear();
        for(int i = 0; i < f; i++)
        {
            int num;
            cin >> num;
            fire[num - 1] = true;
            fi.push_back(num - 1);
        }

        string line;
        cin.ignore();
        g.clear();
        g.resize(10 * inter); //Dont know why simply .resize(inter) give RTE...
        while(getline(cin, line) && line != "")
        {
            stringstream ss;
            ss << line;
            int u, v, w;
            ss >> u >> v >> w;
            g[u - 1].push_back(make_pair(v - 1, w));
            g[v - 1].push_back(make_pair(u - 1, w));
        }
        int ans;
        int min = INT_MAX;
        for(int i = 0; i < inter; i++)
        {
            fi.push_back(i);
            int md = dijkstra();
            if(min > md)
            {
                min = md;
                ans = i;
            }
            fi.pop_back();
        }
        cout << ans + 1 << "\n";
        if(t > 0) cout << "\n";
    }
    return 0;
}
