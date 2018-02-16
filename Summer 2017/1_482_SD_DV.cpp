#include<iostream>
#include<map>
#include<set>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	set<int> key;
	int t,temp;
	cin>>t;
	cin.ignore();
	string temp2;
	map<int,string> final;
	string line;
	map<int,string>::iterator it;
	while(t--)
	{
		getline(cin,line);
		getline(cin,line);
		stringstream strm;
		strm<<line;
		getline(cin,line);
		stringstream strm2;
		strm2<<line;
		while(strm>>temp)
		{
			strm2>>temp2;
			final[temp]=temp2;
		}
		for(it=final.begin();it!=final.end();it++)
		{
			cout<<it->second<<endl;
		}
		if(t!=0)
			cout<<endl;
		final.clear();
	}
	return 0;
}
