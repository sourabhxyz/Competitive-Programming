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
        int m;
        cin >> m;
        vector<ii> data;
        int x, y;
        while(cin >> x >> y and (x != 0 || y != 0)) {
            data.push_back(ii(x, y));
        }
        sort(data.begin(), data.end());
        vector<ii> ans;
        int rightmost = 0;
        int i = 0, j;
        while(data[i].second <= 0) i++;
        for(; i < data.size(); i = j) {
            if(data[i].first > rightmost) break;
            for(j = i + 1; j < data.size() and data[j].first <= rightmost; j++) {
                if(data[j].second > data[i].second) {
                    i = j;
                }
            }
            ans.push_back(data[i]);
            rightmost = data[i].second;
            if(rightmost >= m) break;

        }
        if(rightmost < m) {
            cout << "0\n";
        }
        else {
            cout << ans.size() << "\n";
            for (i = 0; i < ans.size(); i++) {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
        }
        if(t) cout << "\n";
    }
    return 0;
}
