#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
typedef pair<int, int> ii;
#define inf 1e8
#define itn int
string s = "abcdefghijklmnopqrstuvwxyz";
map<char, int> mp;
void gen() {
    string ss;
    for (int i = 0; i < 100; i++) {
        ss.push_back('z');
    }
    vector<int> a(100);
    for (int i = 0; i < 100; i++) {
        a[i] = mp[ss[i]];
    }
    a[0] += 5;
    for (int i = 1; i < 100; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < 100; i++) {
        a[i] %= 26;
    }
    for (int i = 0; i < 100; i++) {
        cout << s[a[i]];
    }
    exit(0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //  freopen("inc.txt", "r", stdin);
    //  freopen("outc.txt", "w", stdout);
    // cout << fixed << setprecision(0);
    for (int i = 0; i < 26; i++) mp[s[i]] = i;
//    gen();
    string w;
    cin >> w;
    vector<int> a(w.size());
    if (mp[w[0]] < 5) { // that means mod
        a[0] = 26 + mp[w[0]];
    } else
        a[0] = mp[w[0]];
    for (int i = 1; i < w.size(); i++) {
        if (mp[w[i]] < a[i - 1]) {
            int k = (a[i - 1] - 1 - mp[w[i]]) / 26;
            a[i] = 26 + mp[w[i]] + k * 26;
        } else {
            a[i] = mp[w[i]];
        }
    }
    for (int i = w.size() - 1; i >= 1; i--) {
        a[i] -= a[i - 1];
    }
    a[0] -= 5;
    for (int i = 0; i < w.size(); i++) {
        cout << s[a[i]];
    }
//    for (auto &t : a) cout << t << " ";
}
