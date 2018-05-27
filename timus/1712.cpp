#include <bits/stdc++.h>

using namespace std;
#define data dta
typedef long long int ll;
const double eps = 1e-11;
const double pi = acos(-1);
#define inf 1e14
#define end en
void rotate(vector<vector<int> > &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int> > nmat(m, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nmat[j][n - i - 1] = mat[i][j];
        }
    }
    mat = nmat;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inc.txt", "r", stdin);
    // freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(0);
    vector<vector<int> > mat(4, vector<int> (4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                mat[i][j] = 0;
            } else {
                mat[i][j] = 1;
            }
        }
    }
    char amat[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> amat[i][j];
        }
    }
    string ans;
    for (int i = 0; i < 4; i++) {
        for (int ii = 0; ii < 4; ii++) {
            for (int j = 0; j < 4; j++) {
                if (mat[ii][j] == 1) {
                    ans.push_back(amat[ii][j]);
                }
            }
        }
        rotate(mat);
    }
    cout << ans << "\n";

}
