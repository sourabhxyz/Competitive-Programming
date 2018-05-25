#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int h, w, n;
    cin >> h >> w >> n;
    int cw = 0;
    int cp = 1;
    int cl = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ss = s.size();
        if (cw + ss > w) {
            cl++;
            cw = 0;
        }
        if (cl == h) {
            cl = 0;
            cp++;
        }
        cw += ss;
        cw++;
        if (cw > w) {
            cl++;
            cw = 0;
        }
        if (cl == h) {
            cl = 0;
            cp++;
        }
    }
    if (cl == 0 and cw == 0) cp--;
    cout << cp << "\n";

}