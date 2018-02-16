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
	int t,n,k,p,ans;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k>>p;
		ans=k;
		while(p--)
		{
			if(ans!=n)
			{
				ans++;
			}
			else
			{
				ans=1;
			}
		}
		cout<<"Case "<<i<<": "<<ans<<endl;
	}
    return 0;
}

