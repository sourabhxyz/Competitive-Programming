#include<bits/stdc++.h>

using namespace std;

#define inf 1000000
#define eps 1e-9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("inb.txt", "r", stdin);
    //freopen("outb.txt", "w", stdout);
    cout << fixed << setprecision(2);
    vector<int> fibs(17);
    fibs[0] = 1, fibs[1] = 2;
    for (int i = 2; i <= 16; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    int n;
    double ans[1005], rsum[1005];
    for (int i = 0; i <= 1000; i++) ans[i] = inf;
    ans[0] = rsum[0] = 0;
    for (int i = 0; i < 17; i++) {
        for (int j = fibs[i]; j <= 1000; j++) {
            if (abs(ans[j - fibs[i]] - inf) > eps) {
                double temp = rsum[j - fibs[i]] + 1.6 * fibs[i] - fibs[i + 1];
                if (temp < 0) temp = abs(temp);
                if (ans[j] > temp) {
                    ans[j] = temp;
                    rsum[j] = rsum[j - fibs[i]] + 1.6 * fibs[i] - fibs[i + 1];
                }
            }
        }
    }
    while (cin >> n and n) {
        cout << ans[n] << "\n";
    }
    return 0;
}
