#include<iostream>
#include<string>
#include<map>

using namespace std;
 
int main()
{
	int l;
	string line;
	map<char,int> data;
	map<char,int>::iterator it;
	data['A']=2;
	data['B']=2;
	data['C']=2;
	data['D']=3;
	data['E']=3;
	data['F']=3;
	data['G']=4;
	data['H']=4;
	data['I']=4;
	data['J']=5;
	data['K']=5;
	data['L']=5;
	data['M']=6;
	data['N']=6;
	data['O']=6;
	data['P']=7;
	data['Q']=7;
	data['R']=7;
	data['S']=7;
	data['T']=8;
	data['U']=8;
	data['V']=8;
	data['W']=9;
	data['X']=9;
	data['Y']=9;
	data['Z']=9;
	while(getline(cin,line))
	{
		l=line.size();
		for(int i=0;i<l;i++)
		{
			if(line[i]=='1'||line[i]=='-'||line[i]=='0')
			{
				cout<<line[i];
				continue;
			}	
			it=data.find(line[i]);
			cout<<it->second;
		}	
		cout<<endl;	
	}	
	return 0;
}
