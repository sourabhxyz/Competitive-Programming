#include<bits/stdc++.h>

using namespace std;
#define itn int
typedef long long int ll;
void print(vector<itn> &ans) {
    cout << "[" << ans[0] << ";" << ans[1];
    for (int i = 2; i < ans.size(); i++) {
        cout << "," << ans[i];
    }
    cout << "]\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("inc.txt", "r", stdin);
    freopen("outc.txt", "w", stdout);
    int n, d;
    while (cin >> n >> d) {
        vector<int> ans;
        if (n == 0) {
            ans = {-1, 1};
            print(ans);
            continue;
        }
        if (d < 0) n *= -1, d = -d;
        if (n == 1) {
            ans = {0, d};
            print(ans);
            continue;
        }
        while (n != 1) {
            int q = n / d;
            int r = n % d;
            // in c++ when we divide negative no. with positive no. both quotient and rem are -ve.
            if (n < 0) {
                q--;
                r = r + d;
            }
            ans.push_back(q);
            n = d;
            d = r;
        }
        print(ans);
    }
    return 0;
}