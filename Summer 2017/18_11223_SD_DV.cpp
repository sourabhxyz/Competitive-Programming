#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int length;
	map<string,char> m;
	m[".-"]		= 'A';
	m["-..."]	= 'B';
	m["-.-."]	= 'C';
	m["-.."]	= 'D';
	m["."]		= 'E';
	m["..-."]	= 'F';
	m["--."]	= 'G';
	m["...."]	= 'H';
	m[".."]		= 'I';
	m[".---"]	= 'J';
	m["-.-"]	= 'K';
	m[".-.."]	= 'L';
	m["--"]		= 'M';
	m["-."]		= 'N';
	m["---"]	= 'O';
	m[".--."]	= 'P';
	m["--.-"]	= 'Q';
	m[".-."]	= 'R';
	m["..."]	= 'S';
	m["-"]		= 'T';
	m["..-"]	= 'U';
	m["...-"]	= 'V';
	m[".--"]	= 'W';
	m["-..-"]	= 'X';
	m["-.--"]	= 'Y';
	m["--.."]	= 'Z';
	m["-----"]	= '0';
	m[".----"]	= '1';
	m["..---"]	= '2';
	m["...--"]	= '3';
	m["....-"]	= '4';
	m["....."]	= '5';
	m["-...."]	= '6';
	m["--..."]	= '7';
	m["---.."]	= '8';
	m["----."]	= '9';
	m[".-.-.-"] = '.';
	m["--..--"] = ',';
	m["..--.."] = '?';
	m[".----."] = '\'';
	m["-.-.--"] = '!';
	m["-..-."]	= '/';
	m["-.--."]	= '(';
	m["-.--.-"] = ')';
	m[".-..."]	= '&';
	m["---..."] = ':';
	m["-.-.-."] = ';';
	m["-...-"]	= '=';
	m[".-.-."]	= '+';
	m["-....-"] = '-';
	m["..--.-"] = '_';
	m[".-..-."] = '"';
	m[".--.-."] = '@';
	int n,pos;
	string line;
	bool first=true;
	string sub;
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++)
	{
		if(!first==false)
		{
			first=false;
		}
		else{ cout<<endl; }
		cout<<"Message #"<<i<<endl;
		getline(cin,line);
		while(line.size())
		{
			if(line.find(' ')<8&&(pos=line.find(' '))&&(pos<line.find("  ")))
			{
				
				//else
				//{
					pos=line.find(' ');
					sub=line.substr(0,pos);
					cout<<m[sub];
					line.erase(0,++pos);
					continue;
				//}
			}
			else if(line.find("  ")<8)
			{
				//if(line.find("  "))
				//{
					//cout<<" ";
					pos=line.find(' ');
					sub=line.substr(0,pos);
					cout<<m[sub];
					pos++;
					line.erase(0,++pos);
					cout<<" ";
					continue;
				//}
			}
			else
			{
				length=line.size();
				length;
				sub=line.substr(0,length);
				cout<<m[sub];
				line.erase(0,length);
			}
		}
		cout<<endl;
	}
	return 0;
}
