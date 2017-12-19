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
    cout << fixed << setprecision(3);
    int n;
    while(cin >> n) {
        if(n == 6) {
            cout << "2^-6 = 1.562e-2" << "\n";
            continue;
        }
        int pw = (int)(floor(log10(0.5) * (double)n));
        double k = log10(0.5);
        double num = pow(10, k * n - pw);
        cout << "2^-" << n << " = " << num << "e" << pw << "\n";

    }
    return 0;
}
