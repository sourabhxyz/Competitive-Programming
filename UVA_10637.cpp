#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int t;
vector<int> ans;
vector<bool> chosen;

void bktk(int rem, int parts, int rparts, int lc, int start, int totake) {
    if(rparts == 1) {
        if(rem >= start and gcd(lc, rem) == 1) {
            
            ans.push_back(rem);
            for(int i = 0; i < ans.size(); i++) {
                if(i) cout << " ";
                cout << ans[i];
            }
            cout << "\n";
            ans.pop_back();
        }
        else return;
    }
    else {
       
        int cantake = rem - rparts + 1;
        for(int i = start; i <= cantake; i++) {
            if(chosen[i]) continue;
            if(gcd(i, lc) > 1) continue;
            chosen[i] = true;
            ans.push_back(i);
            bktk(rem - i, parts, rparts - 1, lcm(i, lc), i + 1, totake);
            chosen[i] = false;
            ans.pop_back();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":\n";
        int num, parts;
        cin >> num >> parts;
        if(num < parts) continue;
        if(parts == 0) continue;
        ans.clear();
        for(int i = 0; i < parts - 1; i++) {
            ans.push_back(1);
        }
        ans.push_back(num - parts + 1);
        for(int i = 0; i < ans.size(); i++) {
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
        if(num == parts) continue;
        for(int i = 2; i <= parts; i++) {
            int rem = num - parts + i;
            chosen.assign(100, false);
            ans.clear();
            for(int j = 0; j < parts - i; j++) {
                ans.push_back(1);
            }
            bktk(rem, parts, i, 1, 2, i);
        }
    }
    return 0;
}
