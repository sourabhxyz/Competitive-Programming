#include<iostream>
using namespace std;
int main()
{
	int dx,dy,cx,cy,n;
	do
	{
		cin>>n;
		if(n==0)
			break;
		cin>>dx>>dy;
		for(int i=0;i<n;i++)
		{
			cin>>cx>>cy;
			if(cx==dx||cy==dy)
			{
				cout<<"divisa"<<endl;
				continue;
			}
			if(cx>dx&&cy>dy)
				cout<<"NE"<<endl;
			else if(cx>dx&&cy<dy)
				cout<<"SE"<<endl;
			else if(cx<dx&&cy>dy)
				cout<<"NO"<<endl;
			else if(cx<dx&&cy<dy)
				cout<<"SO"<<endl;
		}
	}while(n!=0);
	return 0;
}

