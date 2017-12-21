#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000
const double PI = 2 * acos(0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(2);
    int num;
    int eight1 = 255;
    while(cin >> num) {
        cout << num << " converts to ";
        int final = 0;
        for(int i = 0; i < 4; i++) {
            int ch = num & eight1;
            num >>= 8;
            final <<= 8;
            final |= ch;
        }
        cout << final << "\n";
    }
    return 0;

}
