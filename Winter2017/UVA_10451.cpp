#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(5);
    double playa;
    int n;
    double pi = 2 * acos(0);
    int k = 1;
    while(cin >> n && n >= 3) {
        cin >> playa;
        if(abs(playa) < 1e-6)
        {
            cout << "Case " << k++ << ": 0.00000 0.00000\n";
            continue;
        }
        double inter = playa;
        inter *= 2;
        inter /= n;
        inter /= sin(2 * pi / n);
        double outr = sqrt(inter);
        double specta = pi * outr * outr - playa;
        //cout << specta << "\n";
        double inr = outr * cos(pi / n);
        double offa = playa - (pi * inr * inr);
        cout << "Case " << k++ << ": " << specta << " " << offa << "\n";
    }
}
