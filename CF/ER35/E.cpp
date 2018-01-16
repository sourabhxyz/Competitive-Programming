#include<bits/stdc++.h>

using namespace std;

bool inside(int totest, pair<int, int> inof) {
    if(totest >= inof.first and totest <= inof.second) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("inc.txt", "r", stdin);
   // freopen("outc.txt", "w", stdout);
    int n, k;
    while (cin >> n >> k) {
        bool valid = true;
        vector<int> arr;
        for (int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        vector<pair<int, int> > a;
        a.push_back(make_pair(1, n));
        for(int i = 0; i < k; i++) {
            int at = arr[i];
            if(!inside(at, a[a.size() - 1])) {
                cout << "-1\n";
                valid = false;
                break;
            }
            int l = a[a.size() - 1].first;
            int r = a[a.size() - 1].second;
            a.pop_back();
            if (at == l) {
                if (l + 1 <= r)
                a.push_back(make_pair(l + 1, r));
            }
            else if (at == r) {
                if (l <= r - 1)
                a.push_back(make_pair(l, r - 1));
            }
            else {
                if (at + 1 <= r)
                a.push_back(make_pair(at + 1, r));
                a.push_back(make_pair(l, at - 1));
            }
        }
        if (!valid) continue;
        for (int i = a.size() - 1; i >= 0; i--) {
            int r = a[i].second;
            int l = a[i].first;
            for (int j = r; j >= l; j--) {
                arr.push_back(j);
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i) cout << " ";
            cout << arr[i];
        }
        cout << "\n";
    }
    return 0;
}
