#include <bits/stdc++.h>

using namespace std;

int n, t;
double p;
double dp[2005][2005];
double eps = 1e-7;

double 	recur(int nn, int tt) {
	if (nn == 0 || tt == 0) return 0;
	if (abs(dp[nn][tt] + 1) > eps) return dp[nn][tt];
	return dp[nn][tt] = p * (1 + recur(nn - 1, tt - 1)) + (1 - p) * recur(nn, tt - 1);
}

int main() {
	// freopen("inb.txt", "r", stdin);
	// freopen("outb.txt", "w", stdout);
	cin >> n >> p >> t;
	for (int i = 0; i < n + 3; i++) {
		for (int j = 0; j < t + 3; j++) {
			dp[i][j] = -1;
		}
	}
	cout << fixed << setprecision(8) << recur(n, t) << "\n";

}
