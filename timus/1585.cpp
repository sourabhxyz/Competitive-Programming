#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     //freopen("inc.txt", "r", stdin);
     //freopen("outc.txt", "w", stdout);
    int n, a[3] = {0, 0, 0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'E') a[0]++;
        else if (s[0] == 'M') a[1]++;
        else a[2]++;
        cin >> s;
    }
    int pos = max_element(a, a + 3) - a;
    if (pos == 0) {
        cout << "Emperor Penguin";
    } else if (pos == 1) {
        cout << "Macaroni Penguin";
    } else {
        cout << "Little Penguin";
    }
    return 0;
}