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
	int n,i;
	string name1,name2;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		getline(cin,name1);
		getline(cin,name2);
		if(name1.size()==name2.size())
		{
			for(i=0;i<name1.size();i++)
			{
				if(name1[i]!='a'&&name1[i]!='e'&&name1[i]!='i'&&name1[i]!='o'&&name1[i]!='u')
				{
					if(name2[i]==name1[i])
					{
						continue;
					}
					else
					{
						cout<<"No"<<endl;
						break;
					}
				}
				else
				{
					if(name2[i]=='a'||name2[i]=='e'||name2[i]=='i'||name2[i]=='o'||name2[i]=='u')
					{
						continue;
					}
					else{
						cout<<"No"<<endl;
						break;
					}
				}
			}
			if(i!=name1.size())
			{
				continue;
			}
			else
			{
				cout<<"Yes"<<endl;
				continue;
			}
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
    return 0;
}

