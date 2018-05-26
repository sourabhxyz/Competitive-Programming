#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
int data[100000], mx[100000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    int n;
    data[0] = mx[0] = 0;
    data[1] = mx[1] = 1;
    for (int i = 2; i <= 99999; i++) {
        if (i & 1) {
            data[i] = data[i / 2] + data[i / 2 + 1];
            mx[i] = max(mx[i - 1], data[i]);
        } else {
            data[i] = data[i / 2];
            mx[i] = max(mx[i - 1], data[i]);
        }
    }
    while (cin >> n and n) {
        cout << mx[n] << "\n";
    }

}