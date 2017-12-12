#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
#define eps 1e-7

ll n;

void truncate(ll &x) {
    ll limit = pow(10, n);
    while(x >= limit) {
        x = x / 10;
    }
}

ll f(ll x)
{
    ll next = x * x;
    ll temp = pow(10, n);
    if(next >= temp) {
        truncate(next);
    }
    return next;
}

ll floydCycleFinding(ll x0) { // function int f(int x) is defined earlier
// 1st part: finding k*mu, hare’s speed is 2x tortoise’s
    ll mx = x0;
    ll tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
    mx = max(mx, max(tortoise, hare));
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare));
        mx = max(mx, max(tortoise, hare));
    }
// 2nd part: finding mu, hare and tortoise move at the same speed
    ll mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;
        mx = max(mx, max(tortoise, hare));
    }
// 3rd part: finding lambda, hare moves, tortoise stays
    ll lambda = 1; hare = f(tortoise);
        mx = max(mx, hare);
    while (tortoise != hare) { hare = f(hare); lambda++;
        mx = max(mx, hare);
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        ll k;
        cin >> n >> k;
        cout << floydCycleFinding(k) << "\n";
    }
}
