#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
bool lucky(int &n) {
    string t = to_string(n);
    int diff = 6 - t.size();
    string s;
    for (int i = 0; i < diff; i++) s.push_back('0');
    s.insert(s.end(), t.begin(), t.end());
    int a = 0;
    for (int i = 0; i < 3; i++) {
        a += s[i] - '0';
    }
    int b = 0;
    for (int i = 5; i >= 3; i--) {
        b += s[i] - '0';
    }
    return a == b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    int a = n - 1, b = n + 1;
    if (lucky(a) or lucky(b)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}