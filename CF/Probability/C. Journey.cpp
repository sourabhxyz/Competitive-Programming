#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> > glist;

double dp(int at, int parent) {
	int sz = glist[at].size();
	if (sz == 1 and at != 1) {
		return 0;
	}
	double p = at == 1 ? (double) 1.0 / (double) sz : (double) 1.0 / (double) (sz - 1);
	double ret = 0;
	for (auto to : glist[at]) {
		if (to != parent)
			ret += p * (1 + dp(to, at));
	}
	return ret;
}


int main() {
	// freopen("inb.txt", "r", stdin);
	// freopen("outb.txt", "w", stdout);
	cin >> n;
	glist.resize(n + 5);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		glist[u].push_back(v);
		glist[v].push_back(u);
	}
	cout << fixed << setprecision(7) << dp(1, -1) << "\n";
}
