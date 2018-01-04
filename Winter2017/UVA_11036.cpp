#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
#define eps 1e-7

ll N, n;
string postfix;

ll f(ll x)
{
    stack<ll> ans;
    for(ll i = 0; i < postfix.size(); i++) {
        if(postfix[i] == 'x') {
            ans.push(x);
        }
        else if(postfix[i] == 'N') {
            ans.push(N);
        }
        else if(isdigit(postfix[i])) {
            ll num = 0;
            while(isdigit(postfix[i])) {
                num *= 10;
                num += (postfix[i] - 48);
                i++;
            }
            i--;
            ans.push(num);
        }
        else {
            ll a = ans.top(); ans.pop();
            ll b = ans.top(); ans.pop();
            if(postfix[i] == '*') {
                b *= a;
            }
            else if(postfix[i] == '+') {
                b += a;
            }
            else {
                b %= a;
            }
            ans.push(b % N);
        }
    }
    ll ret = ans.top(); ans.pop();
    return ret;
}

ll floydCycleFinding(ll x0) { // function int f(int x) is defined earlier
// 1st part: finding k*mu, hare’s speed is 2x tortoise’s
    ll tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
// 2nd part: finding mu, hare and tortoise move at the same speed
    ll mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
// 3rd part: finding lambda, hare moves, tortoise stays
    ll lambda = 1; hare = f(tortoise);
    while (tortoise != hare) { hare = f(hare); lambda++; }
    return (lambda);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("ina.txt", "r", stdin);
   // freopen("outa.txt", "w", stdout);
    string line;
    while(getline(cin, line)) {
        stringstream ss;
        ss << line;
        ss >> N >> n;
        string temp;
        postfix.clear();
        while(ss >> temp) postfix += temp;
//        cout << postfix << "\n";
        if(n == 0 && N == 0) break;
        cout << floydCycleFinding(n) << "\n";
//        int now = n;
//        for(int i = 0; i < 20; i++) {
//            cout << now << " " ;
//            now = f(now);
//        }
    }
}
