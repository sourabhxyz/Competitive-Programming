#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-9;
const double pi = acos(-1);
int mat[5][5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(10);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> mat[i][j];
        }
    }
    vector<int> vec;
    for (int i = 1; i < 4; i++) vec.push_back(i);
    int ans = INT_MAX;
    vector<int> path;
    do {
        int local = 0;
        int prev = 0;
        if (vec[2] == 2) continue;
        for (auto &t : vec) {
            local += mat[prev][t];
            prev = t;
        }
        local += mat[prev][4];
        if (ans > local) {
            ans = local;
            path = vec;
        }
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans << "\n";
    cout << "1";
    for (auto &t : path) {
        cout << " " << t + 1;
    }
    cout << " 5";
}