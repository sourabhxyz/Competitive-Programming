#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	int y, w;
	cin >> y >> w;
	int mx = max(y, w);
	int ch = 6 - mx + 1;
	int d = gcd(ch, 6);
	ch /= d; int den = 6 / d;
	cout << ch << "/" << den << "\n";
}
