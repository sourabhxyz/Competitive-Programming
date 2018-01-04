#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<int> a, b;
vector<vector<int> > mem;

int lcs(int i, int j)
{
    if (i == -1 || j == -1) {
        return 0;
    }
    if (mem[i][j] != -1) {
        return mem[i][j];
    }
    int res = 0;
    res = max(res, lcs(i, j - 1));
    res = max(res, lcs(i - 1, j));
    if (a[i] == b[j]) {
        res = max(res, 1 + lcs(i - 1, j - 1));
    }
    mem[i][j] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n1, n2;
    int tc = 1;
    while(cin >> n1 >> n2 and (n1 + n2)) {
        a.resize(n1); b.resize(n2);
        for(int i = 0; i < n1; i++) { cin >> a[i]; }
        for(int i = 0; i < n2; i++) { cin >> b[i]; }
        mem.assign(105, vector<int>(105, -1));
        cout << "Twin Towers #" << tc++ << "\n";
        cout << "Number of Tiles : " << lcs(a.size() - 1, b.size() - 1) << "\n\n";
    }
    return 0;
}
