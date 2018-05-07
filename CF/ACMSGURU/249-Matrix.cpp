#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int g(int n) {
    return (n ^ (n >> 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << m); j++) {
            cout << ((g(i) << m) | g(j)) << " ";
        }
        cout << "\n";
    }
    return 0;
}