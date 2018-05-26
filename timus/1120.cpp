#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    n *= 2;
    int ap = 0;
    int aa = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int p = min(i, n / i);
            if (p <= ap) continue;
            int temp = n / i;
            temp -= (p - 1);
            if (temp and temp % 2 == 0) {
                temp /= 2;
                aa = temp;
                ap = p;
            }
        }
    }
    cout << aa << " " << ap;

}