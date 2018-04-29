#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string given;
        cin >> given;
        string copy = given;
        sort(copy.begin(), copy.end());
        ll permno;
        cin >> permno;
        permno++;
        string ans;
        int next = 0;
        ll fact[21];
        fact[0] = 1;
        for (int i = 1; i <= 20; i++) { fact[i] = fact[i - 1] * i; }
        while (!copy.empty()) {
            while (fact[copy.size() - 1] < permno) {
                permno -= fact[copy.size() - 1]; next++;
            }
            ans += copy[next];
            copy.erase(copy.begin() + next);
            next = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}
