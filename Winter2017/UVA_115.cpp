#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000
const double PI = 2 * acos(0);


int bfs(int from, int end, vector<vector<int> > &glist) {
    vi dist(305, inf);
    dist[from] = 0;
    queue<int> q;
    q.push(from);
    while(!q.empty()) {
        int at = q.front(); q.pop();
        for(auto to : glist[at]) {
            if(dist[to] == inf) {
                dist[to] = dist[at] + 1;
                q.push(to);
            }
        }
    }
    return dist[end];
}

bool isparent(int par, int chi, vector<vector<int> > &child) {
    int dist = bfs(par, chi, child);
    if(dist == inf) return false;
    string toprint;
    while(dist > 2) {
        toprint += "great ";
        dist--;
    }
    if(dist == 2) {
        toprint += "grand parent";
        dist = 0;
    }
    if(dist == 1) {
        toprint += "parent";
        dist = 0;
    }
    cout << toprint << "\n";
    return true;
}

bool ischild(int chi, int par, vector<vector<int> > &parent) {
    int dist = bfs(chi, par, parent);
    if(dist == inf) return false;
    string toprint;
    while(dist > 2) {
        toprint += "great ";
        dist--;
    }
    if(dist == 2) {
        toprint += "grand child";
        dist = 0;
    }
    if(dist == 1) {
        toprint += "child";
        dist = 0;
    }
    cout << toprint << "\n";
    return true;
}

void getplist(int u, vi &list, vector<vector<int> > parent) {
    list.push_back(u);
    if(!parent[u].empty()) getplist(parent[u][0], list, parent);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(2);
    vector<vector<int> > parent;
    vector<vector<int> > child;
    vector<vector<int> > tree;
    string p, q;
    parent.resize(305);
    child.resize(305);
    map<string, int> mp;
    int ver = 0;
    while(cin >> p >> q and p != "no.child") {
        if(mp.find(p) == mp.end()) {
            mp[p] = ver++;
        }
        if(mp.find(q) == mp.end()) {
            mp[q] = ver++;
        }
        parent[mp[p]].push_back(mp[q]);
        child[mp[q]].push_back(mp[p]);
    }
    while(cin >> p >> q) {
        if(mp.find(p) == mp.end() || mp.find(q) == mp.end()) {
            cout << "no relation\n";
            continue;
        }
        if(isparent(mp[p], mp[q], child)) {continue;}
        if(ischild(mp[p], mp[q], parent)) {continue;}
        vi p1list, p2list;
        if(!parent[mp[p]].empty()) getplist(parent[mp[p]][0], p1list, parent);
        if(!parent[mp[q]].empty()) getplist(parent[mp[q]][0], p2list, parent);
        bool found = false;
        for(int i = 0; i < p1list.size(); i++) {
            int p1 = p1list[i];
            for(int j = 0; j < p2list.size(); j++) {
                int p2 = p2list[j];
                if(p1 == p2) {
                    found = true;
                    if(i == j and i == 0) {
                        cout << "sibling\n";
                        j = p2list.size(); i = p1list.size();
                        break;
                    }
                    if(i == j) {
                        cout << i << " cousin\n";
                        j = p2list.size(); i = p1list.size();
                        break;
                    }
                    int a = min(i, j);
                    int b = abs(i - j);
                    cout << a << " cousin removed " << b << "\n";
                    j = p2list.size(); i = p1list.size();
                    break;
                }
            }
        }
        if(!found) {
            cout << "no relation\n";
        }
    }
    return 0;

}
