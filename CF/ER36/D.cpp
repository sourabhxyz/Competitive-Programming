#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
int n, root, ban1, ban2;
vector<vector<int> > glist;
vi path;
vector<int> check;

bool dfs(int u) {
	check[u] = 1;
	path.push_back(u);
	for (auto to : glist[u]) {
		if (u == ban1 and to == ban2) continue;
		if (!check[to]) {
			if (dfs(to)) {
				return true;
			}
		} else if (check[to] == 1) {
			root = to;
			return true;
		}
	}
	check[u] = 2;
	path.pop_back();
	return false;
}

vi getCycle() {
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			if (dfs(i)) {
				break;
			}
		}
	}
	vi cycle;
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == root) {
			for (int j = i; j < path.size(); j++) {
				cycle.push_back(path[j]);
			}
			cycle.push_back(root);
			break;
		}
	}
	path.clear();
	return cycle;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	check.assign(n, 0);
	glist.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		glist[u].push_back(v);
	}
	ban1 = ban2 = -1;
	vi cc = getCycle();
	if (cc.empty()) {
		cout << "YES\n";
		return 0;
	}
	for (int i = 0; i < cc.size() - 1; i++) {
		ban1 = cc[i], ban2 = cc[i + 1];
		check.assign(n, 0);
		vi cc2 = getCycle();
		if (cc2.empty()) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
