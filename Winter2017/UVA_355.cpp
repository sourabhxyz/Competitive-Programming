#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
#define eps 1e-7

string num1, num2;

ll base(string nm, int base) {
    ll ret = 0;
    for(int i = nm.size() - 1; i >= 0; i--) {
        if(isdigit(nm[i])) {
            ret += (nm[i] - 48) * pow(base, nm.size() - i - 1);
        }
        else ret += (nm[i] - 65 + 10) * pow(base, nm.size() - i - 1);
    }
    return ret;
}

bool valid(string nm, int base) {
    for(int i = 0; i < nm.size(); i++) {
        if(isdigit(nm[i])) {
            if(nm[i] >= base + 48) return false;
        }
        else {
            if(nm[i] >= base - 10 + 65) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string num;
    int base1, base2;
    while(cin >> base1 >> base2 >> num) {
        if(!valid(num, base1)) {
            cout << num << " is an illegal base " << base1 << " number\n";
            continue;
        }
        ll val = base(num, base1);
        if(val == 0) {
            cout << num << " base " << base1 << " = " << val << " base " << base2 << "\n";
            continue;
        }
        string ans;
        int digits = floor(1 + (log(val) / log(base2)));
        for(int i = digits - 1; i >= 0; i--) {
            ll den = pow(base2, i);
            if(val < den) {
                ans.push_back(48);
                continue;
            }
            ll digit = val / den;
            if(digit > 9) {
                ans.push_back(65 + digit - 10);
            }
            else ans.push_back(digit + 48);
            val = val % den;
        }
        cout << num << " base " << base1 << " = " << ans << " base " << base2 << "\n";
    }
}
