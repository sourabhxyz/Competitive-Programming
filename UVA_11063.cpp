#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-12;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    int n;
    int tc = 1;
    while(cin >> n) {
        cout << "Case #" << tc++ << ": It is ";
        vector<int> arr(n);
        bool valid = true;
        int prev = -1;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] < 1) valid = false;
            if(arr[i] <= prev) {
                valid = false;
            }
            prev = arr[i];
        }
        vector<bool> test(100005, false);
        if(!valid) {
            cout << "not a B2-Sequence.\n\n";
            continue;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(!test[arr[i] + arr[j]]) {
                    test[arr[i] + arr[j]] = true;
                }
                else {
                    valid = false;
                    j = n; i = n;
                }
            }
        }
        if(!valid) {
            cout << "not ";
        }
        cout << "a B2-Sequence.\n\n";
    }
    return 0;
}
