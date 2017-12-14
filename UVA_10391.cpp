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
    map<string, int> data;
    string temp;
    vector<string> data2;
    while(cin >> temp) {
        data[temp] = 1;
        data2.push_back(temp);
    }
    for(int i = 0; i < data2.size(); i++) {
        string word = data2[i];
        for(int j = 1; j < word.size(); j++) {
            string a = word.substr(0, j);
            string b = word.substr(j, word.size() - j);
            if(data.find(a) != data.end() and data.find(b) != data.end()) {
                cout << word << "\n";
                break;
            }
        }
    }
    return 0;
}
