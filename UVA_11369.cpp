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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> data;
        data.resize(n);
        for(int i = 0; i < n; i++ ) {
            cin >> data[i];
        }
        sort(data.begin(), data.end());
        ll dis = 0;
        for(int i = data.size() - 1; i >= 0; i -= 3) {
            if(i >= 2) dis += data[i - 2];
        }
        cout << dis << "\n";
    }
    return 0;
}
