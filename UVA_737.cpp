#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(6);
    int n;
    while(cin >> n and n) {
        int lx = INT_MIN, ly = INT_MIN, lz = INT_MIN, ux = INT_MAX, uy = INT_MAX, uz = INT_MAX;
        for(int i = 0; i < n; i++) {
            int x, y, z, ext;
            cin >> x >> y >> z >> ext;
            lx = max(lx, x);
            ly = max(ly, y);
            lz = max(lz, z);
            ux = min(ux, x + ext);
            uy = min(uy, y + ext);
            uz = min(uz, z + ext);
        }
        int area = (ux - lx) * (uy - ly) * (uz - lz);
        if(area <= 0) {
            cout << "0\n";
        }
        else
            cout << area << "\n";
    }
    return 0;
}
