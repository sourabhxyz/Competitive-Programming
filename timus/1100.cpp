#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
struct team {
    int id, i;
    int solv;
    team() {}
    team(int ii, int jj, int iii) {
        id = ii; solv = jj; i = iii;
    }
    bool operator < (const team &other) const {
        if (solv == other.solv) return i <  other.i;
        return solv > other.solv;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   //  freopen("inc.txt", "r", stdin);
   //  freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int n;
    cin >> n;
    vector<team> data;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        data.push_back(team(a, b, i));
    }
    sort(data.begin(), data.end());
    for (auto &t : data) {
        cout << t.id << " " << t.solv << "\n";
    }
    return 0;
}