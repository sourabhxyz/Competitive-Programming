#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<string> fix(string word) {
    string ret;
    int i = -1;
    vector<string> toret;
    while(i != word.size()) {
        i++;
        ret.clear();
        for (; i < word.size(); i++) {
            if ((word[i] >= 97 and word[i] <= 122) || (word[i] == '-') || (word[i] == '\'')) {
                if(word[i] == '-' || word[i] == '\'') continue;
                ret.push_back(word[i]);
            }
            else break;
        }
        if(!ret.empty())
            toret.push_back(ret);
    }
    return toret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    vector<string> data;
    string temp;
    bool first = true;
    while(cin >> temp) {
        map<int, int> mp;
        while (first || cin >> temp) {
            first = false;
            if(temp[0] == '#') {
                first = true;
                break;
            }
            if (temp[temp.size() - 1] == '-') {
                string word = temp;
                string temp2;
                word.pop_back();
                while (cin >> temp2 and temp2[temp2.size() - 1] == '-') {
                    word += temp2;
                    word.pop_back();
                }
                word += temp2;
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                vector<string> fd = fix(word);
                for(int i = 0; i < fd.size(); i++) {
                    mp[fd[i].size()]++;
                }
            } else {
                string word = temp;
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                vector<string> fd = fix(word);
                for(int i = 0; i < fd.size(); i++) {
                    mp[fd[i].size()]++;
                }
            }
        }
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << " " << it->second << "\n";
        }
        cout << "\n";
    }
    return 0;
}
