#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;


int n, h;
vector<int> ans;

void bktk(int num, int start) {
    if(__builtin_popcount(num) == h) {
        ans.push_back(num);
    }
    else {
        for(int i = start; i < n; i++) {
            if((num & (1 << i)) == 0) {
                num |= (1 << i);
                bktk(num, i + 1);
                num &= (~(1 << i));
            }
        }
    }
}

void print(int at) {
    string num;
    for(int i = 0; i < n; i++) {
        if((at & (1 << i)) == 0) {
            num += "0";
        }
        else num += "1";
    }
    reverse(num.begin(), num.end());
    cout << num;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> h;
        one = (1 << n) - 1;
        ans.clear();
        bktk(0, 0);
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            int at = ans[i];
            print(at);
        }
        if(t) cout << "\n";
    }
    return 0;
}
