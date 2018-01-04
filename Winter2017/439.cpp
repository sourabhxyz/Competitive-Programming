#include<bits/stdc++.h>

using namespace std;

#define INF 10000

int mat[8][8];
int dr[] = {1, -1, -2, 2, 2, -2, 1, -1};
int dc[] = {2, 2, 1, 1, -1, -1, -2, -2};

bool bound(int r, int c)
{
    if(r < 0 || c < 0 || r >= 8 || c >= 8)
        return false;
    return true;
}

void matz()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            mat[i][j] = 1;
        }
    }
}

int bfs(int startr, int startc, int endr, int endc)
{
    int dist[8][8];
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            dist[i][j] = INF;
        }
    }
    queue<int> q;
    q.push(startr);
    q.push(startc);
    dist[startr][startc] = 0;
    while(!q.empty())
    {
        int nowr = q.front(); q.pop();
        int nowc = q.front(); q.pop();
        if(nowr == endr && nowc == endc) return dist[endr][endc];
        for(int i = 0; i < 8; i++) {
            int tor = nowr + dr[i];
            int toc = nowc + dc[i];
            if(bound(tor, toc) && mat[tor][toc] && dist[tor][toc] == INF) {
                q.push(tor);
                q.push(toc);
                dist[tor][toc] = dist[nowr][nowc] + 1;
            }
        }
    }
    return dist[endr][endc];
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    char c;
    while(cin >> c)
    {
        char sc, ec;
        sc = c;
        int startc = c - 97;
        int startr;
        cin >> startr;
        startr--;
        int endc, endr;
        cin >> c >> endr;
        ec = c;
        endc = c - 97;
        endr--;
        matz();
        cout << "To get from " << sc << (startr + 1) << " to " << ec << (endr + 1) << " takes " << bfs(startr, startc, endr, endc) << " knight moves.\n";
    }
    return 0;
}
