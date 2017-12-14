#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool isPalindrome(string a) {
    string nw = a;
    reverse(nw.begin(), nw.end());
    return nw == a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string s;
    while(cin >> s) {
        int cnt = 0;
        map<string, int> mp;
        for(int len = 1; len <= s.size(); len++) {
            vector<string> sub;
            for(int i = 0; i <= s.size() - len; i++) {
                sub.push_back(s.substr(i, len));
            }
            for(int i = 0; i < sub.size(); i++) {
                if(mp.find(sub[i]) == mp.end()) {
                    mp[sub[i]] = 1;
                    if(isPalindrome(sub[i])) cnt++;
                }
            }
        }
        cout << "The string '" << s << "' contains " << cnt << " palindromes.\n";
    }

    return 0;
}
