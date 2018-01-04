//Courtesy: https://www.youtube.com/watch?v=NnD96abizww

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

void printsol(int ui, int li) {
    ui--; li--;
    vector<string> ans;
    while(ui || li) {
        if(a[ui] == b[li]) {
            ans.push_back(a[ui]);
            ui--; li--;
            continue;
        }
        if(ui and mem[ui][li] == mem[ui - 1][li]) {
            ui--;
            continue;
        }
        if(li and mem[ui][li] == mem[ui][li - 1]) {
            li--;
            continue;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    a.resize(105); b.resize(105);
    string temp;
    while(cin >> temp) {
        int k = 2;
        a[k - 1] = temp;
        while(cin >> a[k++] and a[k - 1][0] != '#');
        k--;
        int l = 1;
        while(cin >> b[l++] and b[l - 1][0] != '#');
        l--;
        mem.assign(105, vector<int>(105, 0));
        lcs(k, l);
        printsol(k, l);
    }
    return 0;
}
