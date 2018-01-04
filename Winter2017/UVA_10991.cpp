#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(6);
    double pi = 2 * acos(0);
    int cases;
    cin >> cases;
    while(cases--) {
        double r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        double a = r1 + r2, b = r2 + r3, c = r3 + r1;
        double s = (a + b + c) / 2;
        double triarea = s * (s - a) * (s - b) * (s - c);
        triarea = sqrt(triarea);
        double theta1 = acos((a * a + c * c - b * b) / (2 * a * c));
        double theta2 = acos((a * a + b * b - c * c) / (2 * a * b));
        double theta3 = acos((b * b + c * c - a * a) / (2 * b * c));
        double area1 = r1 * r1 * theta1 / 2;
        double area2 = r2 * r2 * theta2 / 2;
        double area3 = r3 * r3 * theta3 / 2;
        double ans = triarea - area1 - area2 - area3;
        cout << ans << "\n";
    }
}
