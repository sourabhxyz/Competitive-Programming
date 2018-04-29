#include <bits/stdc++.h>

using namespace std;

long long int n, p;

int main() {
	 // freopen("inb.txt", "r", stdin);
	 // freopen("outb.txt", "w", stdout);
	cin >> n >> p;
	vector<pair<long long int, long long int> > lr(n);
	vector<long long int> cnt(n);
	for (int i = 0; i < n; i++) {
		cin >> lr[i].first >> lr[i].second;
		cnt[i] = lr[i].second - lr[i].first + 1;
	}
	double res = 0;
	for (int i = 0; i < n - 1; i++) {
		pair<long long int, long long int> a = lr[i], b = lr[i + 1];
		long long int cnta = (lr[i].second / p - (lr[i].first - 1) / p);
		double temp = cnta * cnt[i + 1];
		long long int cntb = (lr[i + 1].second / p - (lr[i + 1].first - 1) / p);
		temp += cntb * cnt[i];
		temp -= cnta * cntb;
		temp /= (double) cnt[i] * cnt[i + 1];
		res += temp;
	}
	pair<long long int, long long int> a = lr[n - 1], b = lr[0];
	long long int cnta = (lr[n - 1].second / p - (lr[n - 1].first - 1) / p);
	double temp = cnta * cnt[0];
	long long int cntb = (lr[0].second / p - (lr[0].first - 1) / p);
	temp += cntb * cnt[n - 1];
	temp -= cnta * cntb;
	temp /= (double) cnt[n - 1] * cnt[0];
	res += temp;
	cout << fixed << setprecision(8) <<  res * 2000 << "\n";
}
