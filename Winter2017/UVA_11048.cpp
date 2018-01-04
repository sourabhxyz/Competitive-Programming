#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int numdiff(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

bool same(string a, string b) {
    int pos1;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            pos1 = i;
            break;
        }
    }
    char temp = a[pos1];
    a[pos1] = a[pos1 + 1];
    a[pos1 + 1] = temp;
    return a == b;
}

bool valid(string lar, string smal) {
    int pos;
    string tt;
    tt = lar;
    tt.pop_back();
    if(tt == smal) return true;

    for(int i = 0; i < smal.size(); i++) {
        if(smal[i] != lar[i]) {
            pos = i;
            break;
        }
    }
    string nw;
    for(int i = 0; i < lar.size(); i++) {
        if(i == pos) continue;
        nw.push_back(lar[i]);
    }
    return nw == smal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    cin >> n;
    vector<string> dict;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        dict.push_back(temp);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string temp;
        cin >> temp;
        bool check1 = false;
        for(int j = 0; j < n; j++) { //check1
            if(temp == dict[j]) {
                check1 = true;
                cout << temp << " is correct\n";
                break;
            }
        }
        if(check1) continue;
        bool check2 = false;
        for(int j = 0; j < n; j++) {
            if(abs((int)temp.size() - (int)dict[j].size()) == 1) {
                string a, b;
                if(temp.size() > dict[j].size()) a = temp, b = dict[j];
                else a = dict[j], b = temp;
                if(valid(a, b)) {
                    cout << temp << " is a misspelling of " << dict[j] << "\n";
                    check2 = true;
                    break;
                }
            }
            else if(temp.size() == dict[j].size() and (numdiff(temp, dict[j]) == 1 || same(temp, dict[j]))) {
                cout << temp << " is a misspelling of " << dict[j] << "\n";
                check2 = true;
                break;
            }
        }
        if(check2) continue;
        cout << temp << " is unknown\n";
    }
    return 0;
}
