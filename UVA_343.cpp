#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
#define eps 1e-7

string num1, num2;

ll base(string nm, int base) {
    ll ret = 0;
    for(int i = nm.size() - 1; i >= 0; i--) {
        if(isdigit(nm[i])) {
            ret += (nm[i] - 48) * pow(base, nm.size() - i - 1);
        }
        else ret += (nm[i] - 65 + 10) * pow(base, nm.size() - i - 1);
    }
    return ret;
}

bool valid(string nm, int base) {
    for(int i = 0; i < nm.size(); i++) {
        if(isdigit(nm[i])) {
            if(nm[i] >= base + 48) return false;
        }
        else {
            if(nm[i] >= base - 10 + 65) {
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
    string line;
    while(getline(cin, line)) {
        stringstream ss;
        ss << line;
        ss >> num1 >> num2;
        //cout << num1 << " " << num2 << "HI\n";
        int base1 = -1, base2 = -1;
        int start1, start2;
        for(int i = 2; i <= 36; i++) {
            if(valid(num1, i)) {
                start1 = i;
                break;
            }
        }
        for(int i = 2; i <= 36; i++) {
            if(valid(num2, i)) {
                start2 = i;
                break;
            }
        }
        for(int i = start1; i <= 36; i++) {
            for(int j = start2; j <= 36; j++) {
            
                if(base(num1, i) == base(num2, j)) {
                    base1 = i; base2 = j;
                    i = 37; j = 37;
                }
            }
        }
        cout << num1 << " ";
        if(base1 != -1) {
            cout << "(base " << base1 << ") = " << num2 << " (base " << base2 << ")\n";
        }
        else cout << "is not equal to " << num2 << " in any base 2..36\n";
    }


}
