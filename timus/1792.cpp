#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
#define inf 1e14
#define end en
bool validHam(int a[]) {
    int d[4];
    for (int i = 0; i < 4; i++) d[i] = a[i];
    int p[4];
    p[1] = (a[1] + a[2] + a[3]) % 2;
    p[2] = (a[0] + a[3] + a[2]) % 2;
    p[3] = (a[0] + a[1] + a[3]) % 2;
    for (int i = 4; i < 7; i++) {
        if (p[i - 3] != a[i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(0);
    int a[7];
    for (int i = 0; i < 7; i++) cin >> a[i];
    if (validHam(a)) {
        for (int i = 0; i < 7; i++) {
            cout << a[i] << " ";
        }
        return 0;
    }
    for (int i = 0; i < 7; i++) {
        a[i] = !a[i];
        if (validHam(a)) {
            for (int j = 0; j < 7; j++) {
                cout << a[j] << " ";
            }
            return 0;
        }
        a[i] = !a[i];
    }
}
