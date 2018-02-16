#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int t,a[3];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		printf("Case %d: %d\n",i,a[1]);
	}
	return 0;
}
