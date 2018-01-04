#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(0);
    long long int N;
    int cas = 1;
    while(cin >> N and N) {
        cout << "Case " << cas++ << ": " << ceil((3 + sqrt(9 + 8 * N)) / 2) << "\n";
    }
}
