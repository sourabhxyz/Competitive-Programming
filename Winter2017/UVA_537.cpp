#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

void initialize(double &to, string line, int pos) {
    string num;
    while(isdigit(line[pos]) || line[pos] == '.') {
        num.push_back(line[pos]);
        pos++;
    }
    to = stod(num);
    if(line[pos] == 'm') { to /= 1000; }
    else if(line[pos] == 'k') { to *= 1000;}
    else if(line[pos] == 'M') { to *= 1000000;}
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    cin.ignore();
    for(int tc = 1; tc <= t; tc++) {
        cout << "Problem #" << tc << "\n";
        string line;
        getline(cin, line);
        double p = 0, u = 0, i = 0;
        int pos1 = line.find("P=");
        if(pos1 != string::npos) {
            pos1 += 2;
            initialize(p, line, pos1);
        }
        pos1 = line.find("U=");
        if(pos1 != string::npos) {
            pos1 += 2;
            initialize(u, line, pos1);
        }
        pos1 = line.find("I=");
        if(pos1 != string::npos) {
            pos1 += 2;
            initialize(i, line, pos1);
        }
//        cout << p << " " << u << " " << i << "\n";
        if(p < eps) {
            p = u * i;
            cout << "P=" << p << "W\n";
        }
        if(u < eps) {
            u = p / i;
            cout << "U=" << u << "V\n";
        }
        if(i < eps) {
            i = p / u;
            cout << "I=" << i << "A\n";
        }
        cout << "\n";
    }

    return 0;
}
