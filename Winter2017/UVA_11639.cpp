#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(6);
    int n;
    cin >> n;
    int tc = 1;
    for(int i = 0; i < n; i++) {
        cout << "Night " << tc++ << ": ";
        int totalarea = 10000;
        int lx1, lx2, ux1, ux2, ly1, ly2, uy1, uy2;
        cin >> lx1 >> ly1 >> ux1 >> uy1 >> lx2 >> ly2 >> ux2 >> uy2;
        int x = max(lx1, lx2), y = max(ly1, ly2), xx = min(ux1, ux2), yy = min(uy1, uy2);
        int intersectarea = 0;
        if(x < xx and y < yy) {
            intersectarea = (yy - y) * (xx - x);
        }
        int guard1area = (ux1 - lx1) * (uy1 - ly1) - intersectarea;
        int guard2area = (ux2 - lx2) * (uy2 - ly2) - intersectarea;
        cout << intersectarea << " " << guard1area + guard2area << " " << totalarea - guard1area - guard2area - intersectarea << "\n";
    }
    return 0;
}
