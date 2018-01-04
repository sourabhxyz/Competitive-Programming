/*Sample input is not the way it should be >.<*/
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000
vector<int> Sequence;
vector<vector<int> > mem;
int lcs(int ui, int li, vector<int> &a, vector<int> &b) {
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
    return mem[ui - 1][li - 1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    int n;
    string line;
    getline(cin, line);
    while(true) {
        n = stoi(line);
        Sequence.resize(n + 1);
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            Sequence[temp] = i + 1;
        }
        vector<int> b;
        b.resize(n + 1);
        cin.ignore();
        while(getline(cin, line) and line.size() > 2) {
            mem.assign(n + 1, vector<int>(n + 1, 0));
            stringstream ss2;
            ss2 << line;
            for(int i = 1; i <= n; i++) {
                int temp;
                ss2 >> temp;
                b[temp] = i;
            }
            int ans = lcs(n + 1, n + 1, Sequence, b);
            cout << ans << "\n";
        }
        break;
    }
    return 0;
}
