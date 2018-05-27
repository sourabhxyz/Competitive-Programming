#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
#define inf 1e14
#define end en

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(0);
    map<string, string> mp1;
    map<string, int> mp2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "register") {
            cin >> s;
            if (mp1.count(s)) {
                cin >> s;
                cout << "fail: user already exists\n";
            } else {
                string pas;
                cin >> pas;
                mp1[s] = pas;
                cout << "success: new user added\n";
            }
        } else if (s == "login") {
            cin >> s;
            string pas;
            cin >> pas;
            if (!mp1.count(s)) {
                cout << "fail: no such user\n";
            } else if (pas != mp1[s]) {
                cout << "fail: incorrect password\n";
            } else if (mp2[s]) {
                cout << "fail: already logged in\n";
            } else {
                mp2[s] = 1;
                cout << "success: user logged in\n";
            }
        } else {
            cin >> s;
            if (!mp1.count(s)) {
                cout << "fail: no such user\n";
            } else if (!mp2[s]) {
                cout << "fail: already logged out\n";
            } else {
                mp2[s] = 0;
                cout << "success: user logged out\n";
            }
        }
    }
}