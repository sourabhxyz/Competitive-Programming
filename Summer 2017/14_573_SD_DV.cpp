#include<iostream>

using namespace std;

int main()
{
	float H,U,D,F,delay,height;
	int day;
	cin>>H>>U>>D>>F;
	while(H)
	{
		day=1;
		delay=(F/100)*U;
		if(U>H)
		{
			cout<<"success on day 1"<<endl;
			cin>>H>>U>>D>>F;
			continue;
		}
		height=U-D;
		if(D>U)
		{
			cout<<"failure on day 1"<<endl;
			cin>>H>>U>>D>>F;
			continue;
		}
		while(height>=0&&height<=H)
		{
			if((height+U-delay)<0)
			{
				day++;
				U=U-delay;
				height-=D;
				continue;
			}
			else
			{
				if(height+U-delay>H)
				{
					day++;
					height=height+U-delay;
					continue;
				}
				height=height+U-delay-D;
				day++;
				U=U-delay;
			}	
		}
		if(height<0)
		{
			cout<<"failure on day "<<day<<endl;
			cin>>H>>U>>D>>F;
			continue;
		}
		else if(height>H)
		{
			cout<<"success on day "<<day<<endl;
			cin>>H>>U>>D>>F;
			continue;
		}
	}
	return 0;
}

