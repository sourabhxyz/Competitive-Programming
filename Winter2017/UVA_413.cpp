#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000

bool inc, ddec;
int incnt, decnt;
int inctime, dectime;

int determine(vector<int> &data) //return 0 if neither, 1 -> inc, 2 -> dec
{
    if(data.size() == 1) return 0;
    int at = data[0];
    for(int i = 1; i < data.size(); i++) {
        if(data[i] > at) {
            return 1;
        }
        if(data[i] < at) {
            return 2;
        }
        at = data[i];
    }
    return 0;
}

void process(vector<int> &data) {
    int at = data[0];
    for(int i = 1; i < data.size(); i++) {
        if(inc) {
            inctime++;
            while(i < data.size() and data[i] >= at) {
                incnt++;
                at = data[i];
                i++;
            }
            if(i != data.size()) {
                inc = false;
                ddec = true;
                i--;
                continue;
            }

        }
        if(ddec) {
            dectime++;
            while(i < data.size() and data[i] <= at) {
                decnt++;
                at = data[i];
                i++;
            }
            if(i != data.size()) {
                i--;
                inc = true;
                ddec = false;
                continue;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(6);
    string line;
    while(getline(cin, line) and line[0] != '0') {
        stringstream ss;
        ss << line;
        int temp;
        vector<int> data;
        while(ss >> temp) {
            if(temp == 0) break;
            data.push_back(temp);
        }
        cout << "Nr values = " << data.size() << ":  ";
        int det = determine(data);
        if(det == 0) {
            cout << "0.000000 0.000000\n";
            continue;
        }
        if(det == 1) {
            inc = true; ddec = false;
        }
        else {
            ddec = true; inc = false;
        }
        incnt = decnt = inctime = dectime = 0;
        process(data);
        double ai, ad;
        inctime == 0 ? ai = 0 : ai = (double)incnt / inctime;
        dectime == 0 ? ad = 0 : ad = (double)decnt / dectime;
        cout << ai << " " << ad << "\n";
    }
    return 0;
}
