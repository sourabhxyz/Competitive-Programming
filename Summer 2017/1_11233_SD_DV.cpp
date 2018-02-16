#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>

using namespace std;

int main()
{
	map<string,string> data;
	map<string,string>::iterator it;
	int l,n;
	string a,b,line;
	cin>>l>>n;
	cin.ignore();
	while(l--)
	{
		cin>>a>>b;
		cin.ignore();
		data[a]=b;
	}
	while(n--)
	{
		cin>>line;
		it=data.find(line);
		if(it!=data.end())
		{
			cout<<data[line]<<endl;
			continue;
		}
		else
		{
			if(line[line.size()-1]=='y'&&(line[line.size()-2]!='a'&&line[line.size()-2]!='e'&&line[line.size()-2]!='i'&&line[line.size()-2]!='o'&&line[line.size()-2]!='u'))
			{
				line.erase(line.begin()+line.size()-1);
				cout<<line<<"ies"<<endl;
				continue;
			}
			else if(line[line.size()-1]=='o'||line[line.size()-1]=='x'||line[line.size()-1]=='s'||(line[line.size()-1]=='h'&&line[line.size()-2]=='c')||(line[line.size()-1]=='h'&&line[line.size()-2]=='s'))
			{
				cout<<line<<"es"<<endl;
				continue;
			}
			else{
				cout<<line<<"s"<<endl;
			}
		}
	}
    return 0;
}

