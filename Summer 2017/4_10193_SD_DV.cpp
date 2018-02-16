#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<cmath>
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int bin2num(string line)
{
	int result=0;
	for(int i=line.size()-1;i>=0;i--)
	{
		if(line[i]=='1')
		{
			result+=pow(2,line.size()-1-i);
		}
	}
	return result;
}
int main()
{
	int n,num1,num2,cases=0;
	string line;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		cases++;
		getline(cin,line);
		num1=bin2num(line);
		getline(cin,line);
		num2=bin2num(line);
		if(gcd(num1,num2)!=1)
		printf("Pair #%d: All you need is love!\n",cases);
		else
		printf("Pair #%d: Love is not all you need!\n",cases);
	}
    return 0;
}

