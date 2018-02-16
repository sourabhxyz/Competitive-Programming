#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>

using namespace std;
int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }
int main()
{
	int N,G;
	while(cin>>N&&N)
	{
		G=0;
		for(int i=1;i<N;i++)
			for(int j=i+1;j<=N;j++)
			{
				G+=GCD(i,j);
			}
		cout<<G<<endl;
	}
    return 0;
}

