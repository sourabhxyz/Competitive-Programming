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
    string qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    string dvorak = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
    string mapping;
    mapping.resize(200);
    for(int i = 0; i < qwerty.size(); i++) {
        mapping[qwerty[i]] = dvorak[i];
    }
    
    string line;
    while(getline(cin, line)) {
        for(int i = 0; i < line.size(); i++) {
            cout << mapping[line[i]];
        }
        cout << "\n";
    }
    return 0;
}
