#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int r;
    cin >> r;
    char c;
    cin >> c;
    if (r <= 2) {
        if (c == 'B' or c == 'C') {
            cout << "aisle";
        } else {
            cout << "window";
        }
    } else if (r <= 20) {
        if (c == 'A' or c == 'F') {
            cout << "window";
        } else {
            cout << "aisle";
        }
    } else {
        if (c == 'A' or c == 'K') {
            cout << "window";
        } else if (c == 'B' or c == 'E' or c == 'J' or c == 'F') {
            cout << "neither";
        } else {
            cout << "aisle";
        }
    }
}