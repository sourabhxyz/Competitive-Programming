#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000
const double PI = 2 * acos(0);

vector<vector<int> > glist;
vector<vector<int> > memo;

int mvc(int at, int flag, int parent) { 
    if(memo[at][flag] != -1) {
        return memo[at][flag];
    }
    if(glist[at].size() == 1 and parent != -1) { //leaf node
        return memo[at][flag] = flag;
    }
    int ans = flag;
    if(flag) // to take this
    {
        for(auto to : glist[at]) {
            if(to != parent)
                ans += min(mvc(to, 0, at), mvc(to, 1, at));
        }
    } else { //we must take its neighbours
        for(auto to : glist[at]) {
            if(to != parent)
                ans += mvc(to, 1, at);
        }
    }
    return memo[at][flag] = ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(2);
    int n;
    while(cin >> n and n) {
        if(n == 1) {
            cin >> n;
            cout << "1\n";
            continue;
        }
        glist.clear();
        glist.resize(n);
        memo.assign(n, vector<int>(2, -1));
        for(int i = 0; i < n; i++) {
            int neigh;
            cin >> neigh;
            glist[i].resize(neigh);
            for(int j = 0; j < neigh; j++) {
                cin >> glist[i][j];
                glist[i][j]--;
            }
        }
        int ans =  min(mvc(0, 0, -1), mvc(0, 1, -1)); //either put or dont put.
        cout << ans << '\n';
    }
    return 0;

}
