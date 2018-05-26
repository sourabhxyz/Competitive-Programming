#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     // freopen("inc.txt", "r", stdin);
     // freopen("outc.txt", "w", stdout);
    string line;
    bool first = true;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '?' or line[i] == '.' or line[i] == '!') first = true;
            else if (line[i] >= 'a' and line[i] <= 'z' and first) {
               line[i] = line[i] + 'A' - 'a';
               first = false;
            } else if (line[i] >= 'A' and line[i] <= 'Z') {
                if (first) first = false;
                else line[i] = line[i] + ('a' - 'A');
            }
        }
        cout << line << "\n";
    }
}