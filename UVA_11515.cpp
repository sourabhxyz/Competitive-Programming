#include<bits/stdc++.h>

using namespace std;

struct circle{
    int x, y, r;
    circle() {}
    circle(int xx, int yy, int rr) {
        x = xx; y = yy; r = rr;
    }
};

bool ok(circle a, circle b) {
    int sqdist = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    if(sqdist > (a.r + b.r) * (a.r + b.r)) {
        return true;
    }
    return false;
}

bool check(vector<circle> &subset) {
    for(int j = 0; j < subset.size(); j++) {
        for(int k = j + 1; k < subset.size(); k++) {
            if(!ok(subset[j], subset[k]))
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(3);
    int t;
    cin >> t;
    while(t--) {
        int c;
        cin >> c;
        if(c == 0) {
            cout << "0\n";
            continue;
        }
        vector<circle> data;
        for(int i = 0; i < c; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            data.push_back(circle(x, y, r));
        }
        if(c == 1) {
            cout << data[0].r * data[0].r << "\n";
            continue;
        }
        int finalans = 0;
        for(int i = 1; i < (1 << c); i++) {
            vector<circle> subset;
            for(int b = 0; b < c; b++) {
                if(i & (1 << b)) {
                    subset.push_back(data[b]);
                }
            }
            if(check(subset)) {
                int ans = 0;
                for(int j = 0; j < subset.size(); j++) {
                    ans += subset[j].r * subset[j].r;
                }
                finalans = max(finalans, ans);
            }
        }
        cout << finalans << "\n";
    }
    return 0;
}
