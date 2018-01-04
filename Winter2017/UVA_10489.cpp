#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n, b;
        cin >> n >> b;
        int res = 0;
        for(int i = 0; i < b; i++) {
            int k;
            cin >> k;
            int inc = 1;
            for(int j = 0; j < k; j++) {
                int temp;
                cin >> temp;
                inc *= (temp % n);
                inc %= n;
            }
            res += (inc % n);
            res %= n;
        }
        cout << res << "\n";
    }
    return 0;
}
