#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int n;
    while(cin >> n and n) {
        map<pair<int, int>, int> mp;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if(a > b) swap(a, b);
            mp[ii(a, b)]++;
        }
        bool yes = true;
        for(auto it : mp) {
            if(it.second % 2 == 0) {
                continue;
            }
            else {
                yes = false;
                break;
            }
        }
        if(yes) {
            cout << "YES\n";
        }
        else cout << "NO\n";

    }
    return 0;
}
