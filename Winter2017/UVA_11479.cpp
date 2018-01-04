#include<bits/stdc++.h>

using namespace std;

int main()
{
    //cout << fixed << setprecision(3);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    long long int a, b, c;
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> a >> b >> c;
        cout << "Case " << tc << ": ";
        if(a <= 0 || b <= 0 || c <= 0) {
            cout << "Invalid\n";
            continue;
        }
        if(a + b <= c || a + c <= b || b + c <= a) {
            cout << "Invalid\n";
            continue;
        }
        if(a == b && b == c) {
            cout << "Equilateral\n";
            continue;
        }
        if(a == b || b == c || a == c) {
            cout << "Isosceles\n";
            continue;
        }
        cout << "Scalene\n";
    }
}
