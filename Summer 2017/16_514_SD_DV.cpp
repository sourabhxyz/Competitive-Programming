/**In this problem the input is always 1 2 3 4 .. N and the required output is given in the question**/
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
	int n,c,j;
	stack<int> cars;
	while(cin>>n&&n)
	{
	 		
		while(1)
		{	
			while(!cars.empty())
			{
				cars.pop();
			}
			j=1;
			for(int i=0;i<n;i++)
			{
				cin>>c;
				if(c==0)	break;
				for(;j<=c;j++)
				{
					cars.push(j);
				}
				if(cars.top()==c) cars.pop();
				
			}
			if(c==0)
			{
				cout<<endl;
				break;
			}
			if(cars.size()==0)
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
    return 0;
}

