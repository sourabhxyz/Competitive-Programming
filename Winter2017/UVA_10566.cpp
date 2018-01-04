#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-5

double x, y, c;

bool test(double b) {
    double den1 = sqrt(x * x - b * b);
    double den2 = sqrt(y * y - b * b);
    double exp = (c / den1) + (c / den2) - 1;
    return exp > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(3);
    while(cin >> x >> y >> c) {
        double low = 0, high = min(x, y);
        while(high - low > EPS) {
            double mid = (high + low) / 2;
            if(test(mid)) {
                high = mid;
            }
            else
                low = mid;
        }
        cout << high << "\n";
    }
    return 0;
}
