#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	string line;
	unsigned long long total;
	float ans;
	map<string,float> data;
	map<string,float>::iterator it;
	cin>>n;
	cin.ignore();
	getline(cin,line);
	while(n--)
	{
		total=0;
		//getline(cin,line);
		while(getline(cin,line))
		{
			if(line=="")
				break;
			
			if(data[line]==0)
				data[line]=1;
			else
			{
				it=data.find(line);
				it->second++;
				total++;
			}	
			
				
		}
		total+=data.size();
		for(it=data.begin();it!=data.end();it++)
		{
			ans=it->second;
			cout<<it->first;
			printf(" %0.4f",ans*100/total);
			cout<<endl;
		}
		data.clear();
		ans=0;
		if(n!=0)
		cout<<endl;	
		
	}
    return 0;
}

