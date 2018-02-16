#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<cmath>
#define PI acos(-1)
using namespace std;

int main()
{
	int x,y;
	double a,b,v,A,s,distx,disty;
	while(cin>>a>>b>>v>>A>>s&&a)
	{
		x=y=0;
		distx=v*s*cos(A*PI/180.0)/2.0;
		disty=v*s*sin(A*PI/180.0)/2.0;
		if(distx>=a/2){
		distx-=a/2;
		x++;}
		if(disty>=b/2){
		disty-=b/2;
		y++;}
		x+=distx/a;
		y+=disty/b;
		cout<<x<<" "<<y<<endl;
		
	}
    return 0;
}

