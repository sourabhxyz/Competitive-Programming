#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct bin{
    char r, o, y, g, b;
    bin() {}

};

int getdiffcnt(bin a, bin b) {
    int cnt = 0;
    if(a.r != b.r) cnt++;
    if(a.o != b.o) cnt++;
    if(a.y != b.y) cnt++;
    if(a.g != b.g) cnt++;
    if(a.b != b.b) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);
    char c;
    string line;
    while(getline(cin, line) and line[0] != '#') {
        bool first = true;
        vector<bin> data;
        while(first || getline(cin, line)) {
            if(line[0] == 'e') break;
            first = false;
            bin temp;
            stringstream ss;
            ss << line;
            while(ss >> c) {
                char at = c;
                ss >> c;
                ss >> c;
                if(at == 'r') {
                     temp.r = c;
                }
                else if(at == 'o') {
                    temp.o = c;
                }
                else if(at == 'y') {
                    temp.y = c;
                }
                else if(at == 'g') {
                    temp.g = c;
                }
                else if(at == 'b') {
                    temp.b = c;
                }
                ss >> c;
            }
            data.push_back(temp);
        }
        int diffcnt = INT_MAX;
        int ans = 1;
        for(int i = 0; i < data.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < data.size(); j++) {
                if(i == j) continue;
                cnt += getdiffcnt(data[i], data[j]);
            }
            if(diffcnt > cnt) {
                diffcnt = cnt;
                ans = i + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
