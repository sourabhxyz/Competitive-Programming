#include<iostream>

using namespace std;

int main()
{
	int n,x,y,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if((a+b)%2!=0)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		x=(a+b)/2;
		y=(a-b)/2;
		if(x<0||y<0)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		else
		{
			cout<<x<<" "<<y<<endl;
		}	
	}
	return 0;
}
