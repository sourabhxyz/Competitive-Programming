#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;


vector<vector<int> > mat;
int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};
int r, c;

bool bound(int nr, int nc) {
    if(nr < 0 || nc < 0 || nr >= r || nc >= c) return false;
    return true;
}

vector<vector<int> > glist;

void addedge(int i, int j) {
    int at = i * 100 + j;
    for(int k = 0; k < 4; k++) {
        int nr = i + dr[k];
        int nc = j + dc[k];
        if(bound(nr, nc)) {
            if(mat[nr][nc] < mat[i][j]) {
                int to = nr * 100 + nc;
                glist[at].push_back(to);
            }
        }
    }
}

vector<bool> visited;
vector<int> ts;

void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < glist[u].size(); i++) {
        int to = glist[u][i];
        if(!visited[to]) {
            dfs(to);
        }
    }
    ts.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--) {
        string name;
        cin >> name >> r >> c;
        mat.clear();
        mat.resize(r);
        glist.clear();
        glist.resize(20010);
        cout << name << ": ";
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int temp;
                cin >> temp;
                mat[i].push_back(temp);
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                addedge(i, j);
            }
        }
        visited.assign(r * 100 + c, false);
        ts.clear();
        for(int i = 0; i < r * 100 + c; i++) {
            if(!visited[i]) dfs(i);
        }
        reverse(ts.begin(), ts.end());
        vector<int> dist(r * 100 + c, 0);
        for(auto at : ts) {
            for(auto to : glist[at]) {
                if(dist[to] > dist[at] - 1) {
                    dist[to] = dist[at] - 1;
                }
            }
        }
        vector<int>::iterator it = min_element(dist.begin(), dist.end());
        cout << abs(*it) + 1 << "\n";
    }
    return 0;
}
