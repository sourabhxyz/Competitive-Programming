#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(6);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int lx = INT_MIN, ly = INT_MIN, ux = INT_MAX, uy = INT_MAX;
        cout << "Case " << tc << ": ";
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            lx = max(lx, x1);
            ly = max(ly, y1);
            ux = min(ux, x2);
            uy = min(uy, y2);
        }
        if(lx < ux and ly < uy) {
            cout << (ux - lx) * (uy - ly) << "\n";
            continue;
        }
        cout << "0\n";
    }
    return 0;
}
