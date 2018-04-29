#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;

int main() {
	// freopen("inb.txt", "r", stdin);
	// freopen("outb.txt", "w", stdout);
	cin >> a >> b >> c >> d;
	double na = 1 - a / b, nb = 1 - c / d;
	double n = na * nb;
	cout << fixed << setprecision(8) << (a / b) / (1 - n);
}
