#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("inc.txt", "r", stdin);
   // freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n * n);
    vector<int> dia[2 * n - 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            dia[i + j].push_back(temp);
        }
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        reverse(dia[i].begin(), dia[i].end());
        for (auto &t : dia[i]) {
            cout << t << " ";
        }
    }
}



