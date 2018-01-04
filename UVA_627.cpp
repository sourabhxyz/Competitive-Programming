#include<bits/stdc++.h>

using namespace std;

#define INF 100000

vector<int> adjlist[305];
int dist[305];
int p[305];

void printpath(int u, int start)
{
    if(u == start) {
        cout << start + 1;
    } else{
        printpath(p[u], start);
        cout << " " << u + 1;
    }
}

int bfs(int start, int end)
{
    for(int i = 0; i < 305; i++) dist[i] = INF;
    memset(p, -1, sizeof p);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        //if(now == end) return dist[end];
        for(int i = 0; i < adjlist[now].size(); i++)
        {
            int to = adjlist[now][i];
            if(dist[to] == INF)
            {
                p[to] = now;
                dist[to] = dist[now] + 1;
                q.push(to);
            }
        }
    }
    if(dist[end] != INF) {
        printpath(end, start);
        cout << "\n";
    }
    else cout << "connection impossible\n";
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << "-----\n";
        for(int i = 0; i < 305; i++) adjlist[i].clear();
        cin.ignore();
        for(int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;
            int start;
            ss >> start;
            start--;
            char c;
            int to;
            while(ss >> c)
            {
                ss >> to;
                to--;
                adjlist[start].push_back(to);
            }
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int start, end;
            cin >> start >> end;
            start--;
            end--;
            bfs(start, end);
        }
    }
    return 0;
}
