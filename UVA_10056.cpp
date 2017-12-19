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
    cout << fixed << setprecision(4);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, i;
        double p;
        cin >> n >> p >> i;
        if(p < eps) {
            cout << "0.0000\n";
            continue;
        }
        double r = pow(1 - p, n);
        double a = p * pow(1 - p, i - 1);
        double ans = a / (1 - r);
        cout << ans << "\n";
    }
    return 0;
}
