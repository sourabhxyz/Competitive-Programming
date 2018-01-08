#include<bits/stdc++.h>

using namespace std;

string a, b;
int mem[25][25];

void fillmem() {
    for (int j = 0; j <= a.size(); j++) mem[0][j] = j;
    for (int i = 0; i <= b.size(); i++) mem[i][0] = i;
    for (int i = 1; i <= b.size(); i++) {
        for (int j = 1; j <= a.size(); j++) {
            if (a[j - 1] == b[i - 1]) mem[i][j] = mem[i - 1][j - 1];
            else mem[i][j] = min(mem[i - 1][j - 1], min(mem[i - 1][j], mem[i][j - 1])) + 1;
        }
    }
}

void print() {
    int i = b.size(), j = a.size();
    while (i || j) {
        if (i and j and a[j - 1] == b[i - 1]) { i--; j--; continue; }
        if (i and j and mem[i][j] == mem[i - 1][j - 1] + 1) {
            cout << "C" << b[i - 1]; if (j <= 9) cout << "0";
            cout << j;
            i--; j--;
            continue;
        }
        if (i and mem[i][j] == mem[i - 1][j] + 1) {
            cout << "I" << b[i - 1];
            if (j <= 9) cout << "0";
            cout << j + 1;
            i--;
            continue;
        }
        else if (j) {
            cout << "D" << a[j - 1];
            if (j <= 9) cout << "0";
            cout << j;
            j--;
        }
    }
    cout << "E\n";
}

void solve() {
    while (cin >> a) {
        if (a == "#") return;
        cin >> b;
        memset(mem, 0, sizeof mem);
        fillmem();
        print();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("ina.txt", "r", stdin);
//    freopen("outa.txt", "w", stdout);
    solve();
    return 0;
}
