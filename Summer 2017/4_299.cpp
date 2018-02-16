#include<iostream>//Just a simple bubble sort problem.
///And imp. note: that with bubble sort also, we are getting the minimum no. of swaps to sort the input
using namespace std;
int main()
{
	int n,temp,swap;
	cin>>n;
	while(n--)
	{
		swap=0;
		int l;
		cin>>l;
		int a[l];
		for(int k=0;k<l;k++)
		{
			cin>>a[k];
		}
		for (int i = 0 ; i < l - 1 ; i++)
    	{
        	for (int j = 0 ; j < l - 1 ; j++)
        	{
            	if ( a[j] > a[j + 1] )
            	{
                	temp = a[j];
                	a[j]=a[j + 1];
                	a[j + 1] = temp;
                	swap++;
            	}
        	}
    	}
    	cout<<"Optimal train swapping takes "<<swap<<" swaps.";
		//if(n!=0)
			cout<<endl;
	}
	return 0;
}
