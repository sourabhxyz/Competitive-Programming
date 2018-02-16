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
	int t,n,m,nshow;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		nshow=0;
		while(n>=m)
		{
			nshow+=n/m;
			n=n/m+n%m;
		}
		if(n==1)
		{
			cout<<nshow<<endl;
		}
		else
		{
			cout<<"cannot do this"<<endl;
		}
	}
    return 0;
}

