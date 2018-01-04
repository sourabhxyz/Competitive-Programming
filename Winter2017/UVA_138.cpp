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
    //cout << fixed << setprecision(0);
    ll a[] = {6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179};
    ll b[] = {8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161};
//    for(ll i = 8; i <= 100000000; i++) {
//        long double temp = i;
//        temp = sqrt(temp) * sqrt((temp + 1) / 2);
//        if(abs(temp - (int)(temp + eps)) < eps) {
//            cout <<temp << ", " << i << "\n";
//        }
//    }
    for(int i = 0; i < 10; i++) {
        cout << setw(10) << a[i] << setw(10) << b[i] << "\n";
    }
    return 0;
}
