#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int n, tott;
vector<int> a, t;

bool test(int pno) {
    vector<int> candidates;
    for (int i = 0; i < n; i++) {
        if (pno <= a[i]) {
            candidates.push_back(t[i]);
        }
    }
    sort(candidates.begin(), candidates.end());
    if (candidates.size() < pno) return false;
    int cnt = 0;
    int tt = 0;
    for (int i = 0; i < candidates.size() and cnt < pno; i++, cnt++) {
        tt += candidates[i];
        if (tt > tott) return false;
    }
    return true;
}

void print(int no) {
    vector<pair<int, int> > candidates;
    cout << no << "\n" << no << "\n";
    for (int i = 0; i < n; i++) {
        if (no <= a[i]) {
            candidates.push_back(make_pair(t[i], i));
        }
    }
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < no; i++) {
        if (i) cout << " ";
        cout << candidates[i].second + 1;
    }
    cout << "\n";
}
void solve() {
    cin >> n >> tott;
    a.clear(); t.clear();
    a.resize(n); t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
    }
    int l = 1, r = n;
    int prevbest = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (test(mid)) {
            l = mid + 1;
            prevbest = mid;
        } else {
            r = mid - 1;
        }
    }
//    cout << prevbest << "\n";
    if (!prevbest) {
        cout << "0\n0\n\n";
        return;
    }
    print(prevbest);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    solve();
    return 0;
}
