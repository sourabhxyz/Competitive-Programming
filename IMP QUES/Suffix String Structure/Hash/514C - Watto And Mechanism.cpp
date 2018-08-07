#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef long long int ll;

set<pair<ll, ll> > hashes;
ll pow1[600000 + 10], pow2[600000 + 10];
const ll p = 3;
ll m1 = 1e9 + 9, m2 = 1e9 + 7;

void pre() {
	pow1[0] = 1, pow2[0] = 1;
	for (int i = 1; i <= 6 * 100000 + 5; i++) {
		pow1[i] = (pow1[i - 1] * p) % m1;
		pow2[i] = (pow2[i - 1] * p) % m2;
	}
}
pair<ll, ll> compute_hash(string const& s) {
	long long hash_value = 0, hash_value2 = 0;
	for (int i = 0; i < s.size(); i++) {
		hash_value = (hash_value + (s[i] - 'a' + 1) * pow1[i]) % m1;
		hash_value2 = (hash_value2 + (s[i] - 'a' + 1) * pow2[i]) % m2;
	}
	return make_pair(hash_value, hash_value2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("ina.txt", "r", stdin);
	// freopen("outa.txt", "w", stdout);
	pre();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		hashes.insert(compute_hash(s));
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		bool ok = false;
		auto hsh = compute_hash(s);
		for (int j = 0; j < s.size() and !ok; j++) {
			char old = s[j];
			for (int k = 0; k < 3; k++) {
				s[j] = k + 97;
				if (s[j] == old) continue;
				ll one = hsh.first;
				ll two = hsh.second;
				one = (one - (old - 'a' + 1) * pow1[j]) % m1;
				if (one < 0) one += m1;
				one = (one + (s[j] - 'a' + 1) * pow1[j]) % m1;
				two  = (two - (old - 'a' + 1) * pow2[j]) % m2;
				if (two < 0) two += m2;
				two = (two + (s[j] - 'a' + 1) * pow2[j]) % m2;
				auto nsh = make_pair(one, two);
				if (hashes.find(nsh) != hashes.end()) {
					ok = true;
					break;
				}
			}
			s[j] = old;
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}