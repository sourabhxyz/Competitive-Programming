#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000

ii ss, ee;

map<pair<int, int>, int> nvalid;


bool bound(int nr, int nc) {
    if(nr < 0 || nc < 0 || nr >= 6 || nc >= 6) return false;
    return true;
}

vector<int> p;
int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};

int bfs() {
    int dist[6][6];
    for(int i = 0; i < 6; i++) for(int j = 0; j < 6; j++) dist[i][j] = inf;
    dist[ss.first][ss.second] = 0;
    queue<ii> q;
    q.push(ss);
    while(!q.empty()) {
        ii at;
        at.first = q.front().first; at.second = q.front().second; q.pop();
        if(at == ee) {
            return dist[ee.first][ee.second];
        }
        for(int i = 0; i < 4; i++) {
            int nr = at.first + dr[i];
            int nc = at.second + dc[i];
            if(bound(nr, nc) and dist[nr][nc] == inf) {
                int a = at.first * 6 + at.second, b = nr * 6 + nc;
                if(nvalid.find(ii(a, b)) == nvalid.end()) {
                    p[b] = a;
                    dist[nr][nc] = dist[at.first][at.second] + 1;
                    q.push(ii(nr, nc));
                }
            }
        }
    }
}
vector<int> path;

void getpath(int u) {
    if(u == (ss.first * 6 + ss.second)) {
        path.push_back(u);
    }
    else {
        getpath(p[u]);
        path.push_back(u);
    }
}

ii brk(int u) {
    int c = u % 6;
    int r = (u - c) / 6;
    return ii(r, c);
}

void processpath() {
    int prev = path[0];
    for(int i = 1; i < path.size(); i++) {
        ii a = brk(prev);
        ii b = brk(path[i]);
        if(a.first == b.first and a.second < b.second) {
            cout << "E";
        }
        if(a.first == b.first and a.second > b.second) {
            cout << "W";
        }
        if(a.second == b.second and a.first < b.first) {
            cout << "S";
        }
        if(a.second == b.second and a.first > b.first) {
            cout << "N";
        }
        prev = path[i];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    while(cin >> ss.second >> ss.first and (ss.first + ss.second)) {
        p.assign(5 * 6 + 6, -1);
        nvalid.clear();
        path.clear();
        ss.first--; ss.second--;
        cin >> ee.second >> ee.first;
        ee.second--; ee.first--;
        for(int i = 0; i < 3; i++) {
            int y, x;
            cin >> y >> x;
            int y2, x2;
            cin >> y2 >> x2;
            if(x == x2 and y == y2) continue; //no wall
            if(y == y2) { //vertical
                int leftc = y - 1;
                for(int k = min(x, x2); k < max(x, x2); k++) {
                    int leftr = k;
                    int rightr = k;
                    int rightc = y;
                    if(bound(leftr, leftc) and bound(rightr, rightc)) {
                        int a = leftr * 6 + leftc, b = rightr * 6 + rightc;
                        nvalid[ii(a, b)] = 1;
                        nvalid[ii(b, a)] = 1;
                    }
                }
            }
            else { //horizontal
                int upr = x - 1;
                for(int k = min(y, y2); k < max(y, y2); k++) {
                    int upc = k;
                    int belowc = k;
                    int belowr = x;
                    if (bound(upr, upc) and bound(belowr, belowc)) {
                        int a = upr * 6 + upc, b = belowr * 6 + belowc;
                        nvalid[ii(a, b)] = 1;
                        nvalid[ii(b, a)] = 1;
                    }
                }
            }
        }
        bfs();
        getpath(ee.first * 6 + ee.second);
        processpath();
        cout << "\n";
    }
    return 0;

}
