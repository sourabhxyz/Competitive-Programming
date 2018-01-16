#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	if (b.size() > a.size()) 
	{
		sort(a.rbegin(), a.rend());
		cout << a << "\n";
		return 0;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		for (int j = a.size() - 1; j >= 0; j--) {
			string temp = a;
			swap(temp[i], temp[j]);
			sort(temp.begin() + i + 1, temp.end());
			if (temp <= b) {
				a = temp;
				break;
			}
		}
	}
	cout << a << "\n";
	return 0;
}
