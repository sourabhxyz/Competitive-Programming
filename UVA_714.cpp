#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double eps = 1e-9;
const int inf = 100000000;
#define itn int
#define tmep temp
#pragma GCC optimize("Ofast")  // tells the compiler to optimize the code for speed to make it as fast as possible (and not look for space)
#pragma GCC optimize ("unroll-loops")  // normally if we have a loop there is a "++i" instruction somewhere. We normally dont care because code inside the loop requires much more time but in this case there is only one instruction inside the loop so we want the compiler to optimize this.
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  // tell the compiler that our cpu has simd instructions and allow him to vectorize our code
int books, scribers;
ll dp[500][500];
ll book[500];
ll recur (int scriber, int start) {
    if (scriber == scribers and start != books) {
        return LLONG_MAX;
    }
    if (scriber == scribers) {
        return 0LL;
    }
    if (dp[scriber][start] != -1) {
        return dp[scriber][start];
    }
    ll mx = LLONG_MIN;
    ll ans = LLONG_MAX;
    ll pc = 0LL;
    for (int i = start; i < books - (scribers - (scriber + 1)); i++) {
        pc += book[i];
        mx = max (pc, recur (scriber + 1, i + 1));
        if (mx < ans) {
            ans = mx;
        }
    }
    return dp[scriber][start] = ans;
}
bool first = false;
void constructSol (int scriber, int start, ll &ans) {
    if (scriber + 1 == scribers) {
        for (int i = start; i < books; i++) {
            if (first)
                cout << " " << book[i];
            else {
                first = true;
                cout << book[i];
            }
        }
        return;
    }
    ll pc = 0LL;
    for (int i = start; i < (books - (scribers - (scriber + 1))); i++) {
        pc += book[i];
        if (first) {
            cout << " " << book[i];
        } else {
            cout << book[i];
            first = true;
        }
        if (max(pc, dp[scriber + 1][i + 1]) == ans) {
            cout << " /";
            constructSol (scriber + 1, i + 1, dp[scriber + 1][i + 1]);
            return;
        }
    }
}

int main() {
//    freopen("ina.txt", "r", stdin);
//    freopen("outa.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> books >> scribers;
        memset (dp, -1, sizeof (dp));
        for (int i = 0; i < books; i++) cin >> book[i];
        ll ans = recur (0, 0);
        first = false;
        vector<string> stck;
        int bgn = books - 1;
        ll cnt = 0;
        int currentSc = 0;
        int lim = bgn + 1 - (scribers - currentSc - 1);
        int hi = 0;
        while (true and bgn >= 0) {
            cnt += book[bgn];
            if (cnt <= ans and hi < lim) {
                hi++;
                stck.push_back (to_string(book[bgn]));
                bgn--;
            } else {
                hi = 0;
                currentSc++;
                lim = bgn + 1 - (scribers - currentSc - 1);
                cnt = 0;
                stck.push_back("/");
            }
        }
        if (stck[stck.size() - 1] == "/") stck.pop_back();
        reverse(stck.begin(), stck.end());
        for (int i = 0; i < stck.size(); i++) {
            if (i) cout << " " << stck[i];
            else cout << stck[i];
        }
//        constructSol (0, 0, dp[0][0]);
        cout << "\n";
    }

}
