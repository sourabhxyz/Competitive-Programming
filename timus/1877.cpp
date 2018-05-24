#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("inc.txt", "r", stdin);
   // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int one, two;
    cin >> one >> two;
    if (!(one & 1) or (two & 1)) cout << "yes\n";
    else cout << "no\n";
}