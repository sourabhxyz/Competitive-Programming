#include<bits/stdc++.h>

using namespace std;

string line[1000];
queue<pair<int, int> > q2;
queue<pair<int, int> > q1;
pair<int, int> e;
int m, n;
bool cannotTake[1000][1000];
int dr[] = {1, -1, -2, 2, 2, -2, 1, -1};
int dc[] = {2, 2, 1, 1, -1, -1, -2, -2};
int ddr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int ddc[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool bound(int r, int c)
{
    if(r < 0 || r >= m || c < 0 || c >= n) return false;
    return true;
}

void poph()
{
    while(!q2.empty())
    {
        pair<int, int> f;
        f.first = q2.front().first; f.second = q2.front().second; q2.pop();
        for(int i = 0; i < 8; i++)
        {
            int nr = f.first + dr[i];
            int nc = f.second + dc[i];
            if(bound(nr, nc) && (nr != e.first || nc != e.second))
            {
                cannotTake[nr][nc] = true;
            }
        }
    }
}

int bfs()
{
    int dist[m][n];
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) dist[i][j] = -1;
    pair<int, int> f;
    f.first = q1.front().first; f.second = q1.front().second;
    //int t1 = q1.front().first, t2 = q2.front().second;
    dist[f.first][f.second] = 0;
    while(!q1.empty())
    {
        int r = q1.front().first, c = q1.front().second; q1.pop();
        for(int i = 0; i < 8; i++)
        {
            int nr = r + ddr[i];
            int nc = c + ddc[i];
            if(bound(nr, nc) && dist[nr][nc] == -1 && !cannotTake[nr][nc])
            {
                q1.push(make_pair(nr, nc));
                dist[nr][nc] = dist[r][c] + 1;
            }
        }
    }
    return dist[e.first][e.second];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        cin >> m >> n;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cannotTake[i][j] = false;
        cin.ignore();
        for(int i = 0; i < m; i++)
        {
            getline(cin, line[i]);
            for(int k = 0; k < n; k++)
            {
                if(line[i][k] == 'Z') {q2.push(make_pair(i, k)); cannotTake[i][k] = true;}
                else if(line[i][k] == 'A') q1.push(make_pair(i, k));
                else if(line[i][k] == 'B') {e.first = i; e.second = k;}
            }
        }
        poph();
        int mv = bfs();
        if(mv == -1) cout << "King Peter, you can't go now!\n";
        else cout << "Minimal possible length of a trip is " << mv << "\n";
    }
}
