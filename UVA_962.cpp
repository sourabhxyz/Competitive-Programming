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
    cout << fixed << setprecision(0);
    int line = 0;
    map<ll, int> mp;
    for(int i = 1; i <= 1000; i++) {
        for(int j = i; j <= 1000; j++) {
            ll num = 1;
            num = num * i * i * i;
            num += (j * j * j);
            mp[num]++;
        }
    }
    vector<ll> ans;
    for(auto it : mp) {
        if(it.second > 1) {
            ans.push_back(it.first);
        }
    }
    ll low, high;
    while(cin >> low >> high) {
        int i = 0;
        while(ans[i] < low) i++;
        high = low + high;
        bool found = false;
        if(line == 51) {
            bool hey = true;
        }
        while(ans[i] >= low and ans[i] <= high) {
            found = true;
            line++;
            cout << ans[i] << "\n";
            i++;
        }
        if(!found) {
            line++;
            cout << "None\n";
        }
//        //---------------------
//        auto it = lower_bound(ans.begin(), ans.end(), low);
//        auto it2 = upper_bound(ans.begin(), ans.end(), high);
//        bool found = false;
//        for(; it != ans.end() and it2 != ans.end() and it != it2; it++) {
//            cout << *it << "\n";
//            found = true;
//        }
//        if(!found) {
//            cout << "None\n";
//        }
    }
    return 0;

}
