#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    vector<char> arr[26];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        char c2;
        cin >> c2;
        arr[c - 'a'].push_back(c2);
    }
    char g;
    cin >> g;
    for (auto &t : arr[g - 'a']) {
        cout << g << t << "\n";
    }
}