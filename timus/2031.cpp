#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
bool valid(int num) {
    while(num) {
        int dg = num % 10;
        if (dg == 0 or dg == 1 or dg == 8 or dg == 6 or dg == 9) {
            num /= 10;
        } else {
            return false;
        }
    }
    return true;
}
void rev(int n) {
    vector<int> ret;
    if (n == 0) {
        cout << "0";
        return;
    }
    while (n) {
        int at = n % 10;
        if (at == 1 or at == 8 or at == 0) {
            ret.push_back(at);
        } else if (at == 9) {
            ret.push_back(6);
        } else {
            ret.push_back(9);
        }
        n /= 10;
    }
    for (auto &t : ret) {
        cout << t;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> pre;
    bool flag = false;
    for (int i = 10; i < 99; i++) {
        if (pre.size() == n) {
            flag = true;
            break;
        }
        if (!valid(i)) {
            pre.clear();
        } else {
            pre.push_back(i);
        }
    }
    if (!flag) {
        cout << "Glupenky Pierre";
        return 0;
    }
    reverse(pre.begin(), pre.end());
    for (auto &t : pre) {
        rev(t);
        cout << " ";
    }

}