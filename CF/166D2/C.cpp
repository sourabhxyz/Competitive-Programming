#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (3 * k > n) {
        cout << "-1\n";
        return 0;
    }
    vector<int> arr(n + 1, 0);
    int prev = n + 1;
    for (int i = 1; i <= k; i++) {
        arr[i] = i;
        arr[prev - 2] = i;
        arr[prev - 1] = i;
        prev -= 2;
    }
    for (int i = k + 1; i < prev; i++) {
        arr[i] = 1;
    }
    if (3 * k == n) {
        arr[k] = 1;
        arr[1] = k;
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
    return 0;
}
