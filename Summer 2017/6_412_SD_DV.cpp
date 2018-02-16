#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int main()
{
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n,num;
	double cnt;
	double tot;
	double pi;
	vector<int> arr;
	while(cin>>n&&n)
	{
		cnt=0;
		tot=0;
		pi=0;
		for(int i=0;i<n;i++)
		{
			cin>>num;
			arr.push_back(num);
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(gcd(arr[i],arr[j])==1)
				{
					cnt++;
				}
				tot++;
			}
		}
		if(cnt!=0)
		{
			//pi=sqrt(6*(tot/cnt));
			//cout<<fixed<<setprecision (6) <<sqrt(6*(tot/cnt))<<endl;
			printf("%0.6f\n",sqrt(6*(tot/cnt)));
		}
		else
		{
			cout<<"No estimate for this data set."<<endl;
		}
		arr.clear();
	}
    return 0;
}

