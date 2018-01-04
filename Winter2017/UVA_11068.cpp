#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a1, b1, c1, a2, b2, c2;
    while(cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2)
    {
        if(!(a1 || b1 || c1 || a2 || b2 || c2)) break;
        c1 *= -1; c2 *= -1;
        int den = a1*b2 - a2*b1;
        if(den == 0)
        {
            cout << "No fixed point exists.\n";
        } else
        {
            double x = double(b1*c2 - b2*c1) / den;
            double y = double(c1*a2 - c2*a1) / den;
            cout << "The fixed point is at " << fixed << setprecision(2) << x << " " << y << "\n";
        }
    }
}
