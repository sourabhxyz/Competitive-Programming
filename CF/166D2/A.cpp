#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inb.txt", "r", stdin);
    // freopen("outb.txt", "w", stdout);
    int y;
    cin >> y;
    for (int i = y + 1; i <= 9012; i++) {
        int temp = i;
        vector<bool> arr(10, false);
        bool ok = true;
        while (temp) {
            if (arr[temp % 10]) {
                ok = false;
                break;
            }
            arr[temp % 10] = true;
            temp /= 10;
        }
        if (ok) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
