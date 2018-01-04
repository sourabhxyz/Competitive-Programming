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
    string num;
    while(cin >> num and num != "0") {
        map<ll, ll> mp;
        cout << "Original number was " << num << "\n";
        ll ans = stoll(num);
        int length = 0;
        while(mp.find(ans) == mp.end()) {
            length++;
            mp[ans] = 1;
            sort(num.begin(), num.end());
            ll a = stoll(num);
            reverse(num.begin(), num.end());
            ll b = stoll(num);
            ans = b - a;
            num = to_string(ans);
            cout << b << " - " << a << " = " << ans << "\n";
        }
        cout << "Chain length " << length << "\n\n";
    }
    return 0;
}
