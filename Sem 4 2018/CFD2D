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
    // freopen("ind.txt", "r", stdin);
    // freopen("outd.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string given;
    cin >> given;
    vector<int> pi = prefix_function(given);
    int n = given.size();
    vector<int> ans (n + 1, 0);
    for (int i = 0; i < n; ++i)
        ++ans[pi[i]];
    for (int i = n - 1; i > 0; --i)
        ans[pi[i-1]] += ans[i];
    int temp = pi[n - 1];
    vector<pair<int, int> > anss;
    anss.push_back(make_pair(given.size(), 1));
    while (temp) {
        anss.push_back(make_pair(temp, ans[temp] + 1));
        temp = pi[temp - 1];
    }
    reverse(anss.begin(), anss.end());

    cout << anss.size() << "\n";
    for (auto pp : anss) {
        cout << pp.first << " " << pp.second << "\n";
    }
    return 0;
}
