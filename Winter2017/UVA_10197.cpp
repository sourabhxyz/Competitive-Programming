#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    bool first = true;
    string port, junk;
    string eu = "eu        ", tu = "tu        ", ele_ela = "ele/ela   ", nos = "nos       ", vos = "vos       ", eles_elas = "eles/elas ";
    nos[1] = 243; vos[1] = 243;
    while(cin >> port >> junk) {
        if(first) first = false;
        else cout << "\n";
        cout << port << " (to " << junk << ")\n";
        if(port.size() < 2) {
            cout << "Unknown conjugation\n";
            continue;
        }
        string det = port.substr(port.size() - 2, 2);
        string root = port.substr(0, port.size() - 2);
        bool found = false;
        string o1 = root, o2 = root, o3 = root, o4 = root, o5 = root, o6 = root;
        o1.push_back('o');
        if(det == "ar") {
            found = true;
            o2 += "as";
            o3 += "a";
            o4 += "amos";
            o5 += "ais";
            o6 += "am";
        }
        else if(det == "er") {
            found = true;
            o2 += "es";
            o3 += "e";
            o4 += "emos";
            o5 += "eis";
            o6 += "em";
        }
        else if(det == "ir") {
            found = true;
            o2 += "es";
            o3 += "e";
            o4 += "imos";
            o5 += "is";
            o6 += "em";
        }
        if(found) {
            cout << eu << o1 << "\n";
            cout << tu << o2 << "\n";
            cout << ele_ela << o3 << "\n";
            cout << nos << o4 << "\n";
            cout << vos << o5 << "\n";
            cout << eles_elas << o6 << "\n";
        }
        else {
            cout << "Unknown conjugation\n";
        }
    }
    return 0;
}
