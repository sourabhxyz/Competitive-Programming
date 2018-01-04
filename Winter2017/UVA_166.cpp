#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int coinValue[] = {5, 10, 20, 50, 100, 200};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(0);
    vector<long long int> shopkeeper;
    shopkeeper.assign(505, INT_MAX);
    shopkeeper[0] = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = coinValue[i]; j <= 500; j++) {
            if(shopkeeper[j - coinValue[i]] != INT_MAX) {
                shopkeeper[j] = min(shopkeeper[j], shopkeeper[j - coinValue[i]] + 1);
            }

        }
    }
    int cnt[6];
    while(true) {
        int sum = 0;
        for(int i = 0; i < 6; i++) {
            cin >> cnt[i];
            sum += cnt[i];
        }
        if(sum == 0) break;
        double val;
        cin >> val;
        val *= 100;
        int value = (int)(val + eps);
        vector<ll> buyer(505, LLONG_MAX);
        buyer[0] = 0;
        for (int i = 0; i < 6; i++) {
            for(int k = 0; k < cnt[i]; k++) {
                for (int j = 500 - coinValue[i]; j >= 0; j--) {
                    if (buyer[j] != LLONG_MAX && buyer[j + coinValue[i]] > buyer[j] + 1)
                        buyer[j + coinValue[i]] = buyer[j] + 1;
                }
            }
        }
        ll ans = LLONG_MAX;
        for(int i = value; i <= 500; i += 5) {
            ll temp = buyer[i];
            int diff = i - value;
            if(diff) {
                temp += shopkeeper[diff];
            }
            if(temp > 0 and ans > temp) {
                ans = temp;
            }
        }
        cout << setw(3) << ans << "\n";
    }
    return 0;
}
