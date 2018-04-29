#include <bits/stdc++.h>

using namespace std;

string input, recieved, manip;
int acat, favor, defavor;

void dfs(int at, int xat) {
	if (at == input.size()) {
		if (xat == acat) favor++;
		else defavor++;
		return;
	}
	char nxt = recieved[at];
	if (nxt != '?') {
		manip.push_back(nxt);
		dfs(at + 1, nxt == '+' ? xat + 1 : xat - 1);
		manip.pop_back();
	} else {
		// op1
		manip.push_back('+');
		dfs(at + 1, xat + 1);
		manip.pop_back();
		manip.push_back('-');
		dfs(at + 1, xat - 1);
	}
}

int main() {
	cin >> input;
	cin >> recieved;
	acat = favor = defavor = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+') acat++;
		else acat--;
	}
	dfs(0, 0);
	double ans = (double)favor / (favor + defavor);
	cout << fixed << setprecision(10) << ans << "\n";
}
