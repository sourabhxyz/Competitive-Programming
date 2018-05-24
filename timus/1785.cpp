#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    if (n <= 4) {
        cout << "few\n";
    } else if (n <= 9) {
        cout << "several\n";
    } else if (n <= 19) {
        cout << "pack\n";
    } else if (n <= 49) {
        cout << "lots\n";
    } else if (n <= 99) {
        cout << "horde\n";
    } else if (n <= 249) {
        cout << "throng\n";
    } else if (n <= 499) {
        cout << "swarm\n";
    } else if (n <= 999) {
        cout << "zounds\n";
    } else {
        cout << "legion\n";
    }
}