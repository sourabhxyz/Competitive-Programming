#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define inf 1e7

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int test;
    cin >> test;
    for (int tc = 1; tc <= test; tc++) {
        cout << "Scenario #" << tc << "\n";
        vector<vector<ii> > glist;
        int V;
        cin >> V;
        glist.resize(V);
        map<string, int> mp;
        for (int i = 0; i < V; i++) {
            string temp;
            cin >> temp;
            mp[temp] = i;
        }
        int E;
        cin >> E;
        for (int i = 0; i < E; i++) {
            string a, b;
            int w;
            cin >> a >> b >> w;
            int u = mp[a], v = mp[b];
            glist[u].push_back(ii(v, w));
        }
        vector<vector<int> > dp(V, vector<int> (V, inf));
        dp[0][0] = 0;
        for (auto to : glist[0]) {
            dp[0][to.first] = min(dp[0][to.first], to.second);
        }
        for (int stops = 1; stops < V; stops++) {
            for (int i = 0; i < V; i++) { dp[stops][i] = dp[stops - 1][i]; }
            for (int i = 0; i < V; i++) {
                for (auto to : glist[i]) {
                    dp[stops][to.first] = min(dp[stops][to.first], dp[stops - 1][i] + to.second);
                }
            }
        }
        int queries;
        cin >> queries;
        while (queries--) {
            int tol;
            cin >> tol;
            if (tol >= V) tol = V - 1;
            if (dp[tol][V - 1] != inf) { cout << "Total cost of flight(s) is $" << dp[tol][V - 1] << "\n"; }
            else cout << "No satisfactory flights\n";
        }
        if (tc != test) cout << "\n";
    }
    return 0;
}
