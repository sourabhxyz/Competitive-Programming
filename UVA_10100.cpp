#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<string> a, b;
vector<vector<int> > mem;

void lcs(int ui, int li) {
    for(int i = 1; i < ui; i++) {
        for(int j = 1; j < li; j++) {
            if(a[i] == b[j]) {
                mem[i][j] = mem[i - 1][j - 1] + 1;
            }
            else {
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
            }
        }
    }
}

vector<string> mod(string given) {
    for(int i = 0; i < given.size(); i++) {
        if(isalpha(given[i]) || isdigit(given[i])) continue;
        else given[i] = ' ';
    }
    stringstream ss;
    ss << given;
    vector<string> toret;
    toret.push_back("");
    string temp;
    while(ss >> temp) {
        toret.push_back(temp);
    }
    return toret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string temp;
    int tc = 1;
    while(getline(cin, temp)) {
        a = mod(temp);
        getline(cin, temp);
        b = mod(temp);
        cout << setw(2) << tc++ << ". ";
        if(a.size() == 1 || b.size() == 1) {
            cout << "Blank!\n";
            continue;
        }
        mem.assign(1005, vector<int>(1005, 0));
        lcs(a.size(), b.size());
        int ans = mem[a.size() - 1][b.size() - 1];
        cout << "Length of longest match: " << ans << "\n";
    }
    return 0;
}
