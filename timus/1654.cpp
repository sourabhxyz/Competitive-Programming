#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
//    string cc;
//    for (int i = 0; i < 200000; i++) {
//        cc.push_back('a');
//    }
//    cout << cc;
//    return 0;
    string given;
    getline(cin, given);
    stack<char> s;
    for (int i = 0; i < given.size(); ) {
        if (s.empty()) {
            s.push(given[i]);
            i++;
            continue;
        }
        if (s.top() == given[i]) {
            s.pop();
            i++;
        } else {
            s.push(given[i]);
            i++;
        }
    }
    string out;
    while (!s.empty()) {
        out.push_back(s.top());
        s.pop();
    }
    reverse(out.begin(), out.end());
    for (auto &c : out) {
        cout << c;
    }
}