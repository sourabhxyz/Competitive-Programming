#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-9;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(10);
    int n;
    double res = 0;
    cin >> n;
    bool pers = true;
    bool th = false;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 3) th = true;
        pers &= (temp == 5);
        res += temp;
    }
    if (th) {
        cout << "None";
        return 0;
    }
    if (pers) {
        cout << "Named";
        return 0;
    }
    res /= n;
    if (res > 4.5 - eps) {
        cout << "High";
    } else {
        cout << "Common";
    } 

}