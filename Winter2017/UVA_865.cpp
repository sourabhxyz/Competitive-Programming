#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    string line;
    getline(cin, line);
    while(t--) {
        getline(cin, line);
        string line2;
        getline(cin, line2);
        map<char, char> mp;
        for(int i = 0; i < line.size(); i++) {
            mp[line[i]] = line2[i];
        }
        cout << line2 << "\n";
        cout << line << "\n";
        while(getline(cin, line) and line != "") {
            for(int i = 0; i < line.size(); i++) {
                if(mp.find(line[i]) == mp.end()) cout << line[i];
                else cout << mp[line[i]];
            }
            cout << "\n";
        }
        if(t) cout << "\n";
    }

    return 0;
}
