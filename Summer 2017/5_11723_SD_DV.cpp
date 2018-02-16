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
	int r,n,cases=0,ans;
	while(cin>>r>>n&&r)
	{
		cases++;
		if(n>=r)
		{
			printf("Case %d: 0\n",cases);
			continue;
		}
		
		ans=33;
		r=r-n;
		for(int j=1;j<=26;j++)
		{
			if(n*j>=r)
			{
				ans=j;
				break;
			}
		}
		if(ans<=26)
		printf("Case %d: %d\n",cases,ans);
		else
		printf("Case %d: impossible\n",cases);
	}
    return 0;
}

