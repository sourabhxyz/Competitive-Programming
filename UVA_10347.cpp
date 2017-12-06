#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(3);
    double a, b, c;
    while(cin >> a >> b >> c) {
        double s = (a + b + c) / 2;
        double area = s * (s - a) * (s - b) * (s - c);
        if(area < 1e-7) {
            cout << "-1.000\n";
            continue;
        }
        area = sqrt(area);
        area *= (double(4) / 3);
        cout << area << "\n";
    }
}
