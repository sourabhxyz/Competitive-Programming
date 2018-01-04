#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
#define eps 1e-7

ll m;

ll base2(string nm, int base) {
    ll ret = 0;
    for(auto c : nm) {
        ret = (ret * base + (c - 48)) % m;
    }
    return ret;
}
ll base(string nm, int base) {
    ll ret = 0;
    for(auto c : nm) {
        ret = (ret * base + (c - 48));
    }
    return ret;
}
string convto(ll val, int base2) {
    string ans;
    if(val == 0) {
        ans = "0";
        return ans;
    }
    int digits = floor(1 + (log(val) / log(base2)));
    for(int i = digits - 1; i >= 0; i--) {
        ll den = pow(base2, i);
        if(val < den) {
            ans.push_back(48);
            continue;
        }
        ll digit = val / den;
        ans.push_back(digit + 48);
        val = val % den;
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int b;
    while(cin >> b and b) {
        string p, mod;
        cin >> p >> mod;
        m = base(mod, b);
        ll result = base2(p, b);
        string ans = convto(result, b);
        cout << ans << "\n";
    }
}
