// Total number of moves to get to 1x1 remains the same
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int moves = 0;
    int r, c;
    cin >> r >> c;
    if (r == 1 and c == 1) {
    } else if (c == 1) {
        moves = r - 1;
    } else if (r == 1) {
        moves = c - 1;
    } else {
        moves = c - 1 + (c * (r - 1));
    }
    if (moves & 1) {
        cout << "[:=[first]";
    } else {
        cout << "[second]=:]";
    }
}


