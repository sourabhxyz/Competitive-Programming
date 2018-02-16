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
int main()
{
	int j,k,temp,l,cases=0,g;
	int x,num,den;
	string line;
	while(cin>>j&&j!=-1)
	{
		cases++;
		stringstream strm;
		cin>>line;
		l=line.size();
		k=line.size()-2-j;
		line.erase(line.begin());
		line.erase(line.begin());
		strm<<line;
		strm>>x;
		if(j!=0)
		{
			temp=x/pow(10,j);
			num=x-temp;
			den=pow(10,k+j)-pow(10,k);
		}
		else
		{
			num=x;
			den=pow(10,k+j);
		}
		g=gcd(num,den);
		printf("Case %d: %d/%d\n",cases,num/g,den/g);
	}
    return 0;
}

