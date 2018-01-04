#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct pilot{
    string oname, lname;
    int min, sec, millisec;
    pilot() {}
    pilot(string onn, int m, int s, int milli, string nn) {
        transform(nn.begin(), nn.end(), nn.begin(), ::tolower);
        oname = onn;
        min = m;
        sec = s;
        millisec = milli;
        lname = nn;
    }
    bool operator < (const pilot &other) const {
        if(min != other.min) return min < other.min;
        if(sec != other.sec) return sec < other.sec;
        if(millisec != other.millisec) return millisec < other.millisec;
        return  lname <= other.lname;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    while(cin >> n) {
        string name;
        int min, sec, millisec;
        string junk;
        vector<pilot> data;
        for(int i = 0; i < n; i++) {
            cin >> name >> junk >> min >> junk >> sec >> junk >> millisec >> junk;
            data.push_back(pilot(name, min, sec, millisec, name));
        }
        sort(data.begin(), data.end());
        int rowno = 1;
        bool newline = false;
        for(int i = 0; i < data.size(); i += 2) {
            cout << "Row " << rowno++ << "\n";
            cout << data[i].oname << "\n";
            if(i + 1 == data.size()) {
                cout << "\n";
                newline = true;
            }
            else cout << data[i + 1].oname << "\n";
        }
        if(!newline)
            cout << "\n";
    }
    return 0;
}
