#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

string int2roman(int n) {
	string roman;
	string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	string hundreds[] = {"", "C"};

	int o = n % 10;
	n /= 10;
	int t = n % 10;
	n /= 10;
	int h = n % 10;
	n /= 10;

	roman +=hundreds[h] + tens[t] + ones[o];//Or 
	//roman=thousands[th] + hundreds[h] + tens[t] + ones[o] but the written one is
	//faster.

	return roman;
}

int main(void) {
	int n,i,v,x,l,c;
	map<int,string> m;
	string line;
	for (int k = 1; k < 101; k++) {
		string roman = int2roman(k);
		//stringstream strm;
		//string num;
		//strm << i;
		//strm >> num;
		//m[roman] = num;
		m[k] = roman;
	}

	while (cin>>n&&n) {
		i=v=x=l=c=0;
		for(int h=1;h<=n;h++)
		{
		
			line=m[h];
			for(int j=0;j<line.size();j++)
			{
				if(line[j]=='X')
				{
					x++;
					continue;
				}
				else if(line[j]=='I')
				{
					i++;
					continue;
				}
				else if(line[j]=='V')
				{
					v++;
					continue;
				}
				else if(line[j]=='L')
				{
					l++;
					continue;
				}
				else if(line[j]=='C')
				{
					c++;
					continue;
				}
			}	 
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,i,v,x,l,c);
	}
	return 0;
}
