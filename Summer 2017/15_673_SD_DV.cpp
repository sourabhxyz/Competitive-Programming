//See only the at the end commented solution using stack.
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
	char c;
	string line;
	int n;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		getline(cin,line);
			if(line=="")
			{
				cout<<"Yes"<<endl;
			}
			else
				{	
					for(int i=0;i<line.size();i++)
					{
						if(line[i]==' ')
						{
							line.erase(line.begin()+i);
							i--;
							continue;
						}
						else
						{
							if(line[i]=='('||line[i]=='[')
							{
								continue;
							}
							else if(line[i]==')'&&line[i-1]=='(')
							{
								line.erase(line.begin()+i-1);
								line.erase(line.begin()+i-1);
								i=i-2;
								continue;
							}
							else if(line[i]==']'&&line[i-1]=='[')
							{
								line.erase(line.begin()+i-1);
								line.erase(line.begin()+i-1);
								i=i-2;
								continue;
							}
							
						}
					}
					if(line.size()!=0)
						cout<<"No"<<endl;
					else
						cout<<"Yes"<<endl;
				}
	}
    return 0;
}
/*
while(tc--)
    {
        //cin>>s;
        getline(cin, s);
        int sl=s.size();
        stack<char>stk;
        for(int i=0;i<sl;i++)
        {
            if(!stk.empty() && s[i]==')' && stk.top()=='(')
                stk.pop();
            else if(!stk.empty() && s[i]==']' && stk.top()=='[')
                stk.pop();
            else stk.push(s[i]);
        }
        if(stk.empty())
            cout<<"Yes\n";
        else cout<<"No\n";

        //cout<<"Case "<<kk++<<": "<< <<"\n";
    }

    return 0;
}
*/
