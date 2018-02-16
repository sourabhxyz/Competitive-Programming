#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
int main()
{
	int t,m,k,length;
	cin>>t;
	char c;
	double money;
	string line;
	pair<char,double> x;
	map<char,double> weight;
	map<char,double>::iterator it;
	for(int i=0;i<t;i++)
	{
		money=0;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>x.first;
			cin>>x.second;
			weight.insert(x);
		}
		cin>>m;
		cin.ignore();
		while(m--)
		{
			getline(cin,line);
			length=line.size();
			for(int l=0;l<length;l++)
			{
				it=weight.find(line[l]);
				if(it != weight.end())
					money+=(*it).second;	
				}
		}
		money/=100;
		printf("%0.2f$\n", money);	
		weight.clear();
	}
	
	return 0;
}
