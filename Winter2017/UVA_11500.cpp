#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(1);
    double ev1, ev2, at, d;
    while(cin >> ev1 >> ev2 >> at >> d and (ev1 + ev2 + at + d) > eps) {
        double p = at / 6;
        double q = 1 - p;
        double n1 = ceil(ev1 / d);
        double n2 = ceil(ev2 / d);
        double ans;
        if(abs(p - q) < eps) {
            ans = n1 / (n1 + n2);
        }
        else ans = (1 - pow(q / p, n1)) / (1 - pow(q / p, n1 + n2));
        ans *= 100;
        cout << ans << "\n";
    }
    return 0;

}
