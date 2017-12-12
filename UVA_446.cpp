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

string convto(ll val, int base2) {
    string ans;
    if(val == 0) {
        ans = "0000000000000";
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
        if(digit > 9) {
            ans.push_back(65 + digit - 10);
        }
        else ans.push_back(digit + 48);
        val = val % den;
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() < 13) {
        ans.push_back('0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        string num1, num2;
        int base1 = 16, base2 = 2;
        char c;
        cin >> num1 >> c >> num2;
        ll val1 = base(num1, base1);
        ll val2 = base(num2, base1);
        string bin1 = convto(val1, 2), bin2 = convto(val2, 2);
        ll ans;
        cout << bin1 << " " << c << " " << bin2 << " = ";
        if(c == '+') cout << val1 + val2;
        else if(c == '-') cout << val1 - val2;
        cout << "\n";
    }
}
