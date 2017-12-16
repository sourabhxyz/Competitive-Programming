#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vector<int> > mem;

int solve() {
    string x;
    getline(cin, x);
    for(int i = 0; i <= x.size(); i++) mem[i][0] = mem[0][i] = i;
    string y = x;
    reverse(y.begin(), y.end());
    for(int i = 1; i <= x.size(); i++) {
        for(int j = 1; j <= y.size(); j++) {
            if (x[i - 1] == y[j - 1])
                mem[i][j] = mem[i - 1][j - 1];
            else
                mem[i][j] = min(mem[i - 1][j - 1], min(mem[i][j - 1], mem[i - 1][j])) + 1;

        }
    }
    return mem[x.size()][y.size()] / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    mem.assign(1005, vector<int>(1005, 0));
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": " << solve() << "\n";
    }
    return 0;
}
