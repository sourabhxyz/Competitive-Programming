#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<string> data;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        data.clear();
        string temp;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            data.push_back(temp);
        }
        sort(data.begin(), data.end());
        bool consistent = true;
        for(int i = 0; i < n - 1; i++) {
            string a = data[i], b = data[i + 1];
            int j = 0;
            for(j = 0; j < a.size(); j++) {
                if(a[j] != b[j]) break;
            }
            if(j == a.size()) {
                consistent = false;
                break;
            }
        }
        if(consistent) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
