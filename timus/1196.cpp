#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int m;
    cin >> m;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if (binary_search(data.begin(), data.end(), temp)) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}