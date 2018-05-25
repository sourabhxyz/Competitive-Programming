#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;

string gena(int n) {
    string sin = "sin(";
    string ret = "sin(";
    for (int i = 1; i <= n - 1; i++) {
        string nn = to_string(i);
        ret.insert(ret.end(), nn.begin(), nn.end());
        if (i & 1) {
            ret.push_back('-');
        } else {
            ret.push_back('+');
        }
        ret.insert(ret.end(), sin.begin(), sin.end());
    }
    string nn = to_string(n);
    ret.insert(ret.end(), nn.begin(), nn.end());
    for (int i = 1; i <= n; i++) {
        ret.push_back(')');
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    string out;
    int cnt = n;
    while (cnt) {
        string anc = gena(n - cnt + 1);
        out.insert(out.end(), anc.begin(), anc.end());
        out.push_back('+');
        string nn = to_string(cnt);
        out.insert(out.end(), nn.begin(), nn.end());
        out.push_back(')');
        out.insert(out.begin(), '(');
        cnt--;
    }
    out.erase(out.begin());
    out.erase(out.end() - 1);
    cout << out << "\n";
}