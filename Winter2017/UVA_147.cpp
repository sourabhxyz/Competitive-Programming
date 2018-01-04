#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vector<double> > memo;
int coinValue[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
double ways(int type, int value) {
    if (value == 0)              return 1;
    if (value < 0 || type == 11)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(2);
    double val;
    memo.assign(11, vector<double>(30000 + 5, -1));
    while(cin >> val) {
        if(val < eps) break;
        cout << fixed << setprecision(2) << setw(6) << val;
        val *= 100;
        int value = (int)(val + eps);
        
        cout << fixed << setprecision(0) << setw(17) << ways(0, value) << "\n";
    }
    return 0;
}
