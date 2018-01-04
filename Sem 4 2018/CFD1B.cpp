#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}
int main() {
    freopen("ind.txt", "r", stdin);
    freopen("outd.txt", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    string given;
    cin >> given;
    vector<int> p = prefix_function(given);
    int check1 = p[given.size() - 1];
    if (check1 == 0) {
        cout << "Just a legend\n";
        return 0;
    }
    for (int i = 0; i < p.size() - 1; i++) {
        if (p[i] == check1) {
            string aa = given.substr(0, check1);
            cout << aa << "\n";
            return 0;
        }
    }
    int check2 = p[p[p.size() - 1] - 1];
    if (check2 != 0) {
        string aa = given.substr(0, check2);
        cout << aa << "\n";
        return 0;
    }
    cout << "Just a legend\n";
    return 0;
}
