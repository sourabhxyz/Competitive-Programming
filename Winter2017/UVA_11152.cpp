#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    long long int a, b, c;
    cout << fixed << setprecision(4);
    double pi = 2 * acos(0);
    while(cin >> a >> b >> c) {
        double s = a + b + c;
        s /= 2;
        double area = s * (s - a) * (s  - b) * (s - c);
        area = sqrt(area);
        double rin = area / s;
        double rout = a * b * c;
        rout /= (4 * area);
        double roses = pi * rin * rin;
        double violets = area - roses;
        double sunflower = pi * rout * rout - area;
        cout << sunflower << " " << violets << " " << roses << "\n";
    }
}
