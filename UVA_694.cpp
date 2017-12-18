#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-12;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(0);
    int tc = 1;
    ll a, l;
    while(cin >> a >> l and (a > 0 || l > 0)) {
        int seql = 0;
        cout << "Case " << tc++ << ": A = " << a << ", limit = " << l << ", number of terms = ";
        while(true) {
            seql++;
            if(a & 1) {
                a = 3 * a + 1;
            }
            else a = a / 2;
            if(a == 1) {
                seql++;
                break;
            }
            if(a > l) {
                break;
            }
        }
        cout << seql << "\n";
    }
    return 0;
}
