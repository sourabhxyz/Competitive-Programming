#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(10);
    double side;
    double pi = 2 * acos(0);
    double ratio = sin(108 * pi / 180) / sin(63 * pi / 180);
    while(cin >> side) {
        cout << side * ratio << "\n";
    }
}
