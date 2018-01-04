/*Was very easy to derive the formula... */

#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-5
double PI = 2 * acos(0);


double a, b;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(10);
    char c;
    int t = 1;
    while(cin >> a >> c >> b) {
        double theta = 2 * asin(b / sqrt(a * a + b * b));
        double k = 400 / (2 * a + (sqrt(a * a + b * b) * theta));
        double length = a * k, width = b * k;
        cout << "Case " << t++ << ": " << length << " " << width << "\n";

    }
    return 0;
}
