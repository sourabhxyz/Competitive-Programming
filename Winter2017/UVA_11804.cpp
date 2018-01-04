#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct player{
    string name; int attack, defend;
    player() {}
    player(string nn, int aa, int dd) {
        name = nn; attack = aa; defend = dd;
    }
    bool operator < (const player &other) const {
        return name <= other.name;
    }
};

int getattcnt(vector<player> &att) {
    int cnt = 0;
    for(int i = 0; i < att.size(); i++) {
        cnt += att[i].attack;
    }
    return cnt;
}

int getdeffcnt(vector<player> &deff) {
    int cnt = 0;
    for(int i = 0; i < deff.size(); i++) {
        cnt += deff[i].defend;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        vector<player> data;
        for(int i = 0; i < 10; i++) {
            string nn; int d, a;
            cin >> nn >> a >> d;
            data.push_back(player(nn, a, d));
        }
        sort(data.begin(), data.end());
        vector<player> fatt;
        vector<player> fdef;
        int maxcnt = 0;
        int maxdcnt = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = i + 1; j < 10; j++) {
                for(int k = j + 1; k < 10; k++) {
                    for(int l = k + 1; l < 10; l++) {
                        for(int m = l + 1; m < 10; m++) {
                            vector<player> att;
                            att.push_back(data[i]); att.push_back(data[j]); att.push_back(data[k]);
                            att.push_back(data[l]); att.push_back(data[m]);
                            int attcnt = getattcnt(att);
                            vector<player> def;
                            for(int d = 0; d < 10; d++) {
                                if(i == d || j == d || k == d || l == d || m == d) continue;
                                def.push_back(data[d]);
                            }
                            int defcnt = getdeffcnt(def);
                            if(attcnt > maxcnt) {
                                maxcnt = attcnt;
                                fatt = att;
                                fdef = def;
                                maxdcnt = defcnt;
                                continue;
                            }
                            if(attcnt == maxcnt) {

                                if(defcnt > maxdcnt) {
                                    maxdcnt = defcnt;
                                    fatt = att;
                                    fdef = def;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << "Case " << tc << ":\n";
        for(int i = 0; i < fatt.size(); i++) {
            if(i == 0) cout << "(";
            else if(i) {
                cout << ", ";
            }
            cout << fatt[i].name;
            if(i == fatt.size() - 1) {
                cout << ")\n";
            }
        }
        for(int i = 0; i < fdef.size(); i++) {
            if(i == 0) cout << "(";
            else if(i) {
                cout << ", ";
            }
            cout << fdef[i].name;
            if(i == fdef.size() - 1) {
                cout << ")\n";
            }
        }
    }
    return 0;
}
