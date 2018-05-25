#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
   int t, tt;
   cin >> t >> tt;
   for (int i = 0; i < 10; i++) {
       int ttt;
       cin >> ttt;
       t += ttt * 20;
   }
   if (t <= tt) {
       cout << "No chance.";
   } else {
       cout << "Dirty debug :(";
   }
}