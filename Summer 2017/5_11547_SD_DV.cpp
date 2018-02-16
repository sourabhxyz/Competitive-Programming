#include<iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		n=(((n*567/9+7492)*235/47)-498)%100;
		n=n-n%10;
		n=n/10;
		if(n<0)
			n=n-2*n;
		cout<<n<<endl;
	}
	return 0;
}
