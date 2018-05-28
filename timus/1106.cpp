#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
typedef pair<int, int> ii;
#define inf 1e8
#define itn int
int n;
vector<vector<int> > glist;
vector<int> comp;
bool bfs(int here) {
    queue<int> q;
    q.push(here);
    comp[here] = 1;
    int cnt = 1;
    while (!q.empty()) {
        int at = q.front(); q.pop();
        for (auto &t : glist[at]) {
            if (comp[t] == -1) {
                comp[t] = !comp[at];
                cnt++;
                q.push(t);
            }
        }
    }
    return cnt == n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  freopen("inc.txt", "r", stdin);
    //  freopen("outc.txt", "w", stdout);
    // cout << fixed << setprecision(0);
    cin >> n;
    glist.resize(n);
    comp.assign(n, -1);
    for (itn i = 0; i < n; i++) {
        int temp;
        while (cin >> temp and temp) {
            temp--;
            glist[i].push_back(temp);
        }
    }
    for (int i = 0; i < n; i++) {
        if (glist[i].size() == 0) {
            cout << "0";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1) bfs(i);
    }
    cout << count(comp.begin(), comp.end(), 1) << "\n";
    for (int i = 0; i < n; i++) {
        if (comp[i] == 1) {
            cout << i + 1 << " ";
        }
    }

}
