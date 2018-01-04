#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    double D, V;
    cout << fixed << setprecision(3);
    double pi = 2 * acos(0);
    while(cin >> D >> V && (D || V)) {
        double lhs = (pi * D * D * D / 4) - V;
        double d;
        d = cbrt(((12 * lhs / pi) - (D * D * D) ) / 2);
        cout << d << "\n";

    }
    return 0;
}
