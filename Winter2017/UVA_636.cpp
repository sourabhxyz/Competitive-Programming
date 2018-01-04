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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string num;
    while(cin >> num and num[0] != '0')
    {
        int start1 = 0;
        for(int i = 0; i < num.size(); i++) {
            start1 = max(start1, num[i] - 48);
        }
        for(int i = start1 + 1; i <= 100; i++) {
            ll val = base(num, i);
            double sqr = sqrt(val);
            if(abs(sqr - (ll)sqr) < eps) {
                cout << i << "\n";
                break;
            }
        }
    }
}
