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
	int n,k,butt,net;
	while(cin>>n>>k)
	{
		butt=n;
		net=n;
		while(butt>=k)
		{
			//temp=butt/k;
			net+=butt/k;
			butt=butt/k + butt%k;
		}
		cout<<net<<endl;
	}
    return 0;
}

