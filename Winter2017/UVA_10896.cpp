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
    while(t--) {
        string line;
        getline(cin, line);
        stringstream ss;
        ss << line;
        vector<string> enc;
        while(ss >> line) {
            enc.push_back(line);
        }
        cin >> line;
        cin.ignore();
        vector<char> cand;

        for(int j = 0; j < 26; j++) {
            string newword;
            for(int k = 0; k < line.size(); k++) {
                newword.push_back(97 + (line[k] - 97 + j) % 26);
            }
            for(int i = 0; i < enc.size(); i++) {
                if(newword == enc[i]) {
                    cand.push_back(j + 97);
                    break;
                }
            }
        }
        sort(cand.begin(), cand.end());
        for(auto c : cand) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}
