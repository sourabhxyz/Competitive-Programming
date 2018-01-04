/*Add n (the last element) to all the subsets of (n - 2) + Add n to all the subsets of (n - 3)*/
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cout << fixed << setprecision(5);
    long long recur[77];
    recur[0] = recur[1] = 1;
    recur[2] = 2;
    for(int i = 3; i <= 76; i++) {
        recur[i] = recur[i - 2] + recur[i - 3];
    }
    int n;
    while(cin >> n) {
        cout << recur[n] << "\n";
    }
}
