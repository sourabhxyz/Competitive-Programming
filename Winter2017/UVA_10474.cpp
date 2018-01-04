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
    int n, q, tc = 1;
    while(cin >> n >> q and (n + q)) {
        cout << "CASE# " << tc++ << ":\n";
        vector<int> data;
        data.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> data[i];
        }
        sort(data.begin(), data.end());
        vector<ii> ndata;
        map<int, int> mp;
        for(int i = 0; i < data.size(); i++) {
            if(mp.find(data[i]) != mp.end()) {
                mp[data[i]]++;
            } else {
                mp[data[i]] = 0;
                ndata.push_back(ii(data[i], 0));
            }
        }
        int cnt = 0;
        for(int i = 0; i < ndata.size(); i++) {
            ndata[i].second = cnt;
            cnt += mp[ndata[i].first];
        }

        for(int i = 0; i < q; i++) {
            int tos;
            cin >> tos;
            int low = 0, high = ndata.size() - 1;
            bool found = false;
            while(low <= high) {
                int mid = (high + low) / 2;
                if(ndata[mid].first == tos) {
                    found = true;
                    cout << tos << " found at " << mid + ndata[mid].second + 1 << "\n";
                    break;
                }
                else if(ndata[mid].first > tos) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            if(!found) {
                cout << tos << " not found\n";
            }
        }
    }
    return 0;
}
