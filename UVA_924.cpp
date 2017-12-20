#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-12;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 100000000

vector<vector<int> > glist;
int v;

ii bfs(int from) {
    vi dist(v, inf);
    dist[from] = 0;
    queue<int> q;
    q.push(from);
    int maxboomcnt = 0;
    int boomday = 0;
    map<int, int> mp;
    while(!q.empty()) {
        int at = q.front(); q.pop();
        for(auto to : glist[at]) {
            if(dist[to] == inf) {
                dist[to] = dist[at] + 1;
                mp[dist[to]]++;
                q.push(to);
            }
        }
    }
    ii ans(0, 0);
    for(auto a : mp) {
        if(a.second > ans.first) {
            ans.first = a.second;
            ans.second = a.first;
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    cin >> v;
    glist.clear(); glist.resize(v);
    for(int i = 0; i < v; i++) {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int to;
            cin >> to;
            glist[i].push_back(to);
        }
    }
    int tc;
    cin >> tc;
    while(tc--) {
        int from;
        cin >> from;
        ii ans = bfs(from);
        if(ans.first == 0) {
            cout << "0\n";
        }
        else {
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    return 0;

}
