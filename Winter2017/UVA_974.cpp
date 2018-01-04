#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000

bool iskap(int num) {
    int sq = num * num;
    string nn = to_string(sq);
    for(int i = 1; i < nn.size(); i++) {
        string a = nn.substr(0, i);
        string b = nn.substr(i, nn.size() - i);
        int n1 = stoi(a), n2 = stoi(b);
        if(n1 > 0 and n2 > 0 and n1 + n2 == num) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(3);
    vector<int> kap;
    for(int i = 9; i <= 40000; i++) {
        if(iskap(i)) {
            kap.push_back(i);
        }
    }
    int n;
    cin >> n;
    for(int tc = 1; tc <= n; tc++) {
        cout << "case #" << tc << "\n";
        int low, high;
        cin >> low >> high;
        bool found = false;
        auto it = lower_bound(kap.begin(), kap.end(), low);
        auto it2 = upper_bound(kap.begin(), kap.end(), high);
        for(; it != it2; it++) {
            found = true;
            cout << *it << "\n";
        }
        if(!found) {
            cout << "no kaprekar numbers\n";
        }
        if(tc != n) cout << "\n";
    }

    return 0;
}
