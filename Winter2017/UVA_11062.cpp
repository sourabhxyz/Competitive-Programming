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
            if ((word[i] >= 97 and word[i] <= 122) || (word[i] == '-')) {
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
    while(cin >> temp) {
        if(temp[temp.size() - 1] == '-') {
            string word = temp;
            string temp2;
            word.pop_back();
            while(cin >> temp2 and temp2[temp2.size() - 1] == '-') {
                word += temp2;
                word.pop_back();
            }
            word += temp2;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            vector<string> fd = fix(word);
            data.insert(data.end(), fd.begin(), fd.end());
        }
        else {
            string word = temp;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            vector<string> fd = fix(word);
            data.insert(data.end(), fd.begin(), fd.end());
        }
    }
    sort(data.begin(), data.end());
    vector<string>::iterator it = unique(data.begin(), data.end());
    data.resize(distance(data.begin(), it));
    for(int i = 0; i < data.size(); i++) {
        cout << data[i] << "\n";
    }
    return 0;
}
