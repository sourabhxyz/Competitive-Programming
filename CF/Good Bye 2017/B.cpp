#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
#define inf 10000000;
ii s, e;
int n, m;
string str[55], path;
map<int, int> mp;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool bound(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m) return false;
    return true;
}

bool valid() {
    ii at = s;
    for (int i = 0; i < path.size(); i++) {
        at.first += dr[mp[path[i] - 48]];
        at.second += dc[mp[path[i] - 48]];
        if (!bound(at.first, at.second) || (str[at.first][at.second] == '#')) {
            return false;
        }
        if (at == e) return true;
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        for (int j = 0; j < str[i].size(); j++) {
            if (str[i][j] == 'S') {
                s.first = i; s.second = j;
            } else if(str[i][j] == 'E') {
                e.first = i; e.second = j;
            }
        }
    }
    cin >> path;
    int cnt = 0;
    vector<int> perm;
    for (int i = 0; i < 4; i++) {
        perm.push_back(i);
    }
    do {
        for (int i = 0; i < 4; i++) {
            mp[perm[i]] = i;
        }
        if (valid()) cnt++;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << cnt << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("ina.txt", "r", stdin);
//    freopen("outa.txt", "w", stdout);
    solve();
    return 0;
}
