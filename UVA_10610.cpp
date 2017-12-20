#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000

int v, m;

struct point{
    double x, y;
    point() {}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
};

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

vector<vector<int> > glist;

int bfs() {
    vi dist(glist.size(), inf);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int at = q.front(); q.pop();
        for(auto to : glist[at]) {
            if(dist[to] == inf) {
                dist[to] = dist[at] + 1;
                q.push(to);
            }
        }
    }
    return dist[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    while(cin >> v >> m and (v + m)) {
        point s;
        cin >> s.x >> s.y;
        vector<point> data;
        glist.clear();
        data.push_back(s);
        point t;
        cin >> t.x >> t.y;
        data.push_back(t);
        point temp;
        cin.ignore();
        string line;
        while(getline(cin, line) and line != "") {
            stringstream ss;
            ss << line;
            ss >> temp.x >> temp.y;
            data.push_back(temp);
        }
        glist.resize(data.size());
        m *= 60;
        for(int i = 0; i < data.size(); i++) {
            for(int j = i + 1; j < data.size(); j++) {
                double d = dist(data[i], data[j]);
                d /= v;
                if(d < (double)m + eps) {
                    glist[i].push_back(j);
                    glist[j].push_back(i);
                }
            }
        }
        int ans = bfs();
        ans == inf ? cout << "No.\n" : cout << "Yes, visiting " << ans - 1 << " other holes.\n";
    }
    return 0;

}
