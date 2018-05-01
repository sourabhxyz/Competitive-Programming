// Would be glad if somebody could tell me why the following solution does not work >.< ...

#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string s;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;
        long long int n1, n2 = 0;
        ss >> n1 >> n2;
        if (n2 == 0) {
            if (n1 == 0) {
                cout << "2 2\n";
            } else if (n1 % 4 == 0) {
                long long int x = 2;
                long long int y = n1 / 2;
                long long int a = (x + y) / 2, b = (y - x) / 2;
                cout << abs(a) << " " << abs(b) << "\n";
            } else if (n1 % 2 != 0) {
                long long int x = 1, y = n1;
                long long int a = (x + y) / 2, b = (y - x) / 2;
                cout << abs(a) << " " << abs(b) << "\n";
            } else {
                cout << "Bachelor Number.\n";
            }
        } else {
            long long int cnta = n2 / 2 - (n1 - 1) / 2;
            long long int cntb = n2 / 4 - (n1 - 1) / 4;
            long long int bach = cnta - cntb;
            cout << bach << "\n";
        }

    }
    cout << "\n";
    return 0;
}
