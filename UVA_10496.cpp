#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define inf 1e7
int rm, cm, sr, sc, beepc;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("ine.txt", "r", stdin);
//	freopen("oute.txt", "w", stdout);
	int ts;
	cin >> ts;
	for (int tc = 0; tc < ts; tc++) {
		cin >> rm >> cm;
		cin >> sr >> sc;
		cin >> beepc;
		vector<ii> mp;
		mp.push_back(ii(sr, sc));
		int dist[rm + 5][cm + 5];
		for (int i = 0; i < rm + 5; i++) {
			for (int j = 0; j < cm + 5; j++) {
				if (i == j) dist[i][j] = 0;
				else dist[i][j] = inf;
			}
		}
		for (int b = 0; b < beepc; b++) {
			int x, y;
			cin >> x >> y;
			mp.push_back(ii(x, y));
			dist[0][b + 1] = abs(y - sc) + abs(x - sr);
			dist[b + 1][0] = abs(y - sc) + abs(x - sr);
		}
		for (int b = 1; b <= beepc; b++) {
			for (int nb = b + 1; nb <= beepc; nb++) {
				dist[b][nb] = abs(mp[b].first - mp[nb].first) + abs(mp[b].second - mp[nb].second);
				dist[nb][b] = abs(mp[b].first - mp[nb].first) + abs(mp[b].second - mp[nb].second);
			}
		}
		for (int k = 0; k <= beepc; k++) {
			for (int i = 0; i <= beepc; i++) {
				for (int j = 0; j <= beepc; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		vector<int> perm;
		for (int i = 1; i <= beepc; i++) perm.push_back(i);
		int ans = inf;
		do {
			int temp = 0;
			int prev = 0;
			for (int i = 0; i < perm.size(); i++) {
				temp += dist[prev][perm[i]];
				prev = perm[i];
			}
			temp += dist[prev][0];
			ans = min(ans, temp);
		} while (next_permutation(perm.begin(), perm.end()));
		cout << "The shortest path has length " << ans << "\n";
	}
}
