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
    int n;
    while(cin >> n and n) {
        bool found = false;
        for(int i = 1; i <= 100000; i++) {
            double at = double(i) * i * i + n;
            at = cbrt(at);
            if(abs(at - (int)(at + eps)) < eps) {
                cout << at << " " << i << "\n";
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "No solution\n";
        }
    }
    return 0;

}
