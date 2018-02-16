#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<stack>
using namespace std;

int main()
{
	int n;
	char c;
	bool repeat=false;
	string line;
	cin>>n;
	cin.ignore();
	getline(cin,line);
	//getline(cin,line);
	while(n--)
	{
		getline(cin,line);
		stack<char> postfix;
		while(1)//while(getline(cin,line))
		{
			if(line=="")
			{
				while(postfix.size())
				{
					cout<<postfix.top();
					postfix.pop();
				}
				cout<<endl;
				if(n!=0)
					cout<<endl;
				break;
			}
			if(line[0]>=48&&line[0]<=57)
			{
				cout<<line[0];
				getline(cin,line);
				continue;
			}
			else
			{
				if((!postfix.size())||postfix.top()=='(')
				{
					postfix.push(line[0]);
					getline(cin,line);
					continue;
				}
				else if(line[0]=='(')
				{
					postfix.push(line[0]);
					getline(cin,line);
					continue;
				}
				else if(line[0]==')')
				{
					while(postfix.top()!='(')
					{
						c=postfix.top();
						cout<<c;
						postfix.pop();
					}
					postfix.pop();
					getline(cin,line);
					continue;
				}
				else
				{
					if((line[0]=='*'||line[0]=='/')&&(postfix.top()=='+'||postfix.top()=='-'))
					{
						postfix.push(line[0]);
						getline(cin,line);
						continue;
					}
					else if((line[0]=='+'||line[0]=='-')&&(postfix.top()=='*'||postfix.top()=='/'))
					{
						c=postfix.top();
						cout<<c;
						postfix.pop();
						continue;
					}
					else
					{
						c=postfix.top();
						cout<<c;
						postfix.pop();
						continue;	
					}
					
				}
			}
		}
		
	}
    return 0;
}

