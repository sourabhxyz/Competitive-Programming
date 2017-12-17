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
    //cout << fixed << setprecision(2);
    int n;
    while(cin >> n and n) {
        vector<int> data;
        data.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> data[i];
        }
        ll cost = 0;
        ll at = data[0];
        for(int i = 1; i < n; i++) {
            cost += abs(at);
            at += data[i];
        }
        cout << cost << "\n";
    }
    return 0;
}
