#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m;
vector<string> words;
string temp;

vector<string> pass;
vector<string> ans;

void masterbktk(int pos) {
    if(pos == temp.size()) {
        string s;
        for(int i = 0; i < pass.size(); i++) {
            s += pass[i];
        }
        ans.push_back(s);
    }
    else {
        if(temp[pos] == '#') {
            for(int i = 0; i < n; i++) {
                pass.push_back(words[i]);
                masterbktk(pos + 1);
                pass.pop_back();
            }
        }
        else if(temp[pos] == '0') {
            for(int i = 0; i < 10; i++) {
                string s = to_string(i);
                pass.push_back(s);
                masterbktk(pos + 1);
                pass.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);

    while(cin >> n) {
        cout << "--\n";
        ans.clear();
        words.clear();
        words.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> words[i];
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> temp;
            masterbktk(0);
            for(int k = 0; k < ans.size(); k++) {
                cout << ans[k] << "\n";
            }
        }
    }

    return 0;
}
