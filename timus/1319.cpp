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
    int d = (2 * n - 1);
    vector<int> dia[d];
    int prev = 1;
    for (int i = 0; i < d; i++) {
        int toput;
        if (i < n) {
            toput = i + 1;
        } else {
            toput = (d - i);
        }
        for (int j = 0; j < toput; j++) {
            dia[i].push_back(prev);
            prev = prev + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int aj = n - j - 1;
            int acd = i + aj;
            int ind;
            if (acd < n) ind = i;
            else {
                int dec = (i + aj - n + 1);
                ind = i - dec;
            }
            cout << dia[acd][ind] << " ";
        }
        cout << "\n";
    }
}



