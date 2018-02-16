#include <bits/stdc++.h>

using namespace std;

int main() {
	char c;
	bool first = true;
	while (cin.get(c)) { //difference between cin >> c and cin.get(c) is that cin >> c will ignore '\n'
	//but cin.get will not.
		if (c == '"') {
			if (first) { first = false; c = '`'; }
			else { first = true; c = '\''; }
			
			cout << c << c;
		} else {
			cout << c;
		}
	}
	
	return 0;
}
