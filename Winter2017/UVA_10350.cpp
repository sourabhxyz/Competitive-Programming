#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int, int> ii;
vector<vector<ii > > glist;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string cname;
    while(cin >> cname) {
        int n, m;
        cin >> n >> m;
        glist.clear();
        glist.resize(n * m);
        for(int i = 0; i < (n - 1) * m; i++) {
            int k = i / m;
            for(int j = 0; j < m; j++) {
                int temp;
                cin >> temp;
                glist[i].push_back(ii(k * m + m + j, temp + 2));
            }
        }
        vector<int> dist(n * m, INF);
        for(int i = 0; i < m; i++) dist[i] = 0;
        for(int i = 0; i < n * m; i++) {
            for(auto to : glist[i]) {
                if(dist[to.first] > dist[i] + to.second) {
                    dist[to.first] = dist[i] + to.second;
                }
            }
        }
        int mn = INT_MAX;
        for(int i = (n - 1) * m; i < n * m; i++) {
            if(mn > dist[i]) {
                mn = dist[i];
            }
        }
        cout << cname << "\n" << mn << "\n";
    }
    return 0;
}
