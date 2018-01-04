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
    cout << fixed << setprecision(2);
    int rules;
    while(cin >> rules and rules) {
        vector<pair<string, string> > data;
        cin.ignore();
        string f, r;
        for(int i = 0; i < rules; i++) {
            getline(cin, f); getline(cin, r);
            data.push_back(make_pair(f, r));
        }
        string line;
        getline(cin, line);
        for(int i = 0; i < rules; i++) {
            int pos;
            f = data[i].first;
            r = data[i].second;
            pos = line.find(f);
            while(pos != string::npos) {
                line.replace(pos, f.size(), r);
                pos = line.find(f);
            }
        }
        cout << line << "\n";
    }

    return 0;
}
