#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

bool contains7(int hh, int mm) {
    string a = to_string(hh);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '7') return true;
    }
    a = to_string(mm);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '7') return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("ine.txt", "r", stdin);
    // freopen("oute.txt", "w", stdout);
    int x, hh, mm;
    cin >> x >> hh >> mm;
    int cnt = 0;
    do {
        if (contains7(hh, mm)) {
            cout << cnt << "\n";
            break;
        }
        cnt++;
        if (mm - x < 0) {
            hh -= 1;
            if (hh < 0) {
                hh = 23;
            }
            mm = 60 - (x - mm);
        } else {
            mm -= x;
        }

    } while (true);
    return 0;
}
