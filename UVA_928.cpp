#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-12;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 100000000

int r, c;
int mat[305][305];
ii ss, ee;
int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};

bool bound(int nr, int nc) {
    if(nr < 0 || nc < 0 || nr >= r || nc >= c) return false;
    return true;
}

struct cor{
    int x, y;
    int dist;
    cor() {}
    cor(int xx, int yy , int dd) {
        x = xx; y = yy; dist = dd;
    }
};

int bfs() {
    queue<cor> q;
    q.push(cor(ss.first, ss.second, 0));
    int step = 0;
    bool visited[r][c][3];
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) for(int k = 0; k < 3; k++) visited[i][j][k] = false;
    while(!q.empty()) {
        ii at;
        at.first = q.front().x; at.second = q.front().y;
        int d = q.front().dist; q.pop();

        if(at == ee) {
            return d;
        }
        step = d + 1;
        step = step % 3;
        if(step == 0) {
            step = 3;
        }
        for(int i = 0; i < 4; i++) {
            int can = step;
            int nr = at.first, nc = at.second;
            bool valid = true;
            while(can--) {
                nr += dr[i];
                nc += dc[i];
                if(bound(nr, nc) and mat[nr][nc] != -1) {
                    continue;
                }
                else {
                    valid = false;
                }
            }
            if(valid and !visited[nr][nc][step % 3]) {
                q.push(cor(nr, nc, d + 1));
                visited[nr][nc][step % 3] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> r >> c;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                char ch;
                cin >> ch;
                if(ch == '.') {
                    mat[i][j] = 1;
                }
                else if(ch == '#') {
                    mat[i][j] = -1;
                }
                else if(ch == 'S') {
                    ss.first = i;
                    ss.second = j;
                    mat[i][j] = 1;
                }
                else if(ch == 'E') {
                    ee.first = i;
                    ee.second = j;
                    mat[i][j] = 1;
                }
            }
        }
        int ans = bfs();
        ans == -1 ? cout << "NO\n" : cout << ans << "\n";
    }
    return 0;

}
