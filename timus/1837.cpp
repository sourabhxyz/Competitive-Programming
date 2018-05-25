#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
vector<vector<int> > glist;
int n;
#define inf 1e9
map<string, int> mp;
int k = 0;
void bfs(int at) {
    vector<int> dist(3 * n, inf);
    dist[at] = 0;
    queue<int> q;
    q.push(at);
    while (!q.empty()) {
        int here = q.front(); q.pop();
        for (auto &to : glist[here]) {
            if (dist[to] == inf) {
                dist[to] = dist[here] + 1;
                q.push(to);
            }
        }
    }
    for (auto &t : mp) {
        cout << t.first << " ";
        if (dist[t.second] == inf) {
            cout << "undefined";
        } else {
            cout << dist[t.second];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cin >> n;
    glist.resize(3 * n);
    for (int i = 0; i < n; i++) {
        vector<int> data;
        for (int j = 0; j < 3; j++) {
            string s;
            cin >> s;
            if (!mp.count(s)) {
                mp[s] = k++;
            }
            data.push_back(mp[s]);
        }
        for (int j = 0; j < 3; j++) {
            for (int jj = j + 1; jj < 3; jj++) {
                glist[data[j]].push_back(data[jj]);
                glist[data[jj]].push_back(data[j]);
            }
        }

    }
    if (!mp.count("Isenbaev")) {
        for (auto &t : mp) {
            cout << t.first << " undefined\n";
        }
        return 0;
    }
    bfs(mp["Isenbaev"]);

}