#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    while(cin >> n) {
        vector<int> data;
        vector<int> arr(n);
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mn = min(mn, arr[i]);
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] == mn) {
                data.push_back(i);
            }
        }
        int prev = data[0];
        int mdist = INT_MAX;
        for(int i = 1; i < data.size(); i++) {
            mdist = min(mdist, data[i] - prev);
            prev = data[i];
        }
        cout << mdist << "\n";
    }
    return 0;
}
