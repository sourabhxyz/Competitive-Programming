#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll fib[51];

void pre() {
    fib[1] = 2;
    fib[2] = 3;
    for(int i = 3; i < 51; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    pre();
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        cout << "Scenario #" << tc << ":\n";
        cout << fib[n] << "\n\n";
    }
    return 0;
}
