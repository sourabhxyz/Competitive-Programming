#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<cmath>
using namespace std;
char matrix[100][100];
int main()
{
	int t,k;
	double num;
	string line;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		k=0;
		getline(cin,line);
		num=sqrt(line.size());
		if(num==floor(num))
		{
			for(int i=0;i<num;i++)
			{
				for(int j=0;j<num;j++)
				{
					matrix[i][j]=line[k];
					k++;
				}
			}
			for(int j=0;j<num;j++)
			{
				for(int i=0;i<num;i++)
				{
					cout<<matrix[i][j];
				}
			}
			cout<<endl;
		}
		else
		{
			cout<<"INVALID"<<endl;
		}
		
	}
    return 0;
}

