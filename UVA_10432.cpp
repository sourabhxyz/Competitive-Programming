#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(3);
    double n, r;
    while(cin >> r >> n)
    {
        cout << n * r * r / 2 * sin(2 * acos(-1.0) / n) << "\n";
    }
    return 0;
}
