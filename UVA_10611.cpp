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
    cin >> n;
    vector<ll> data;
    data.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        ll h;
        cin >> h;
        if(h > data[data.size() - 1]) {
            cout << data[data.size() - 1] << " X\n";
            continue;
        }
        if(h < data[0]) {
            cout << "X " << data[0] << "\n";
        }
        vector<ll>::iterator it = lower_bound(data.begin(), data.end(), h), it2 = upper_bound(data.begin(), data.end(), h);
        int pos1 = -1;
        if(it != data.end()) {
            pos1 = it - data.begin();
            pos1--;
        }
        if(pos1 != -1) cout << data[pos1] << " ";
        else cout << "X ";
        if(it2 != data.end()) cout << *it2 << "\n";
        else cout << "X\n";
    }
    return 0;
}
