#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(6);
    int t;
    cin >> t;
    while(t--) {
        long long int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == b && b == c && c == d) {
            cout << "square\n";
            continue;
        }
        if((a == b && c == d) || (a == c && b == d) || (a == d && b == c)) {
            cout << "rectangle\n";
            continue;
        }
        if(a + b + c > d && a + b + d > c && a + c + d > b && b + c + d > a) {
            cout << "quadrangle\n";
            continue;
        }
        cout << "banana\n";
    }
}
