#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool equal(string a, string b) {
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        string user, judge;
        getline(cin, user); getline(cin, judge);
        string userwithoutspace;
        if(user.size() != judge.size()) {
            for(int i = 0; i < user.size(); i++) {
                if(user[i] != ' ') {
                    userwithoutspace.push_back(user[i]);
                }
            }
            if(equal(userwithoutspace, judge)) {
                cout << "Output Format Error\n";
                continue;
            }
            else {
                cout << "Wrong Answer\n";
                continue;
            }
        }
        if(equal(user, judge)) {
            cout << "Yes\n";
        }
        else cout << "Wrong Answer\n";
    }
    return 0;
}
