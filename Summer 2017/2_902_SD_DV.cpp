#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	while (cin >> n) {
	    cin >> s;
	    map<string, int> freq;
	    int m = 0;
	    string password;
	    for (int i = 0; i <= s.size() - n; i++) {
			string w = s.substr(i, n);
			freq[w]++;
			if (freq[w] > m) {
				m = freq[w];
				password = w;
			}
	    }
    	cout << password << "\n";
	}
	return 0;
}
