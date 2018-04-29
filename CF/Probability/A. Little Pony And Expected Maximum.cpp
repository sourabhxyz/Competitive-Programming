#include <bits/stdc++.h>

using namespace std;

int m, n;

double comp(int k) {
	return pow(double(k) / m, n) - pow(double((k - 1)) / m, n);
}

int main() {
	// freopen("inb.txt", "r", stdin);
	// freopen("outb.txt", "w", stdout);
	cin >> m >> n;
	double ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += i * (comp(i));
	}
	cout << fixed << setprecision(6) << ans << "\n";
}
