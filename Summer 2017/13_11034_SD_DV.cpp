#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<deque>

using namespace std;

int main()
{
	float length,l,amnt;
	string place,line,pos;
	deque<float> left;
	deque<float> right;
	deque<float>::iterator it;
	int n,m,trip;
	cin>>n;
	//cout<<left.size();
	//cout<<right.size();
	while(n--)
	{
		pos="left";
		trip=0;
		cin>>l>>m;
		l*=100;
		cin.ignore();
		while(m--)
		{
			cin>>length>>place;
			if(place=="left")
				left.push_back(length);
			else
				right.push_back(length);
		}
		while(left.size()!=0||right.size()!=0)
		{
			amnt=0;
			if(left.size()!=0)
			{
				if(pos=="right")
					trip++;
				pos="right";
				trip++;
				for(it=left.begin();left.size()!=0;it++)
				{
					amnt+=*it;
					if(amnt>l)
						break;
					else
					{
						//cout<<*it<<endl;
						left.erase(it);
						//cout<<left.size()<<endl;
						//cnt++;
					}
				}
			}
			
			amnt=0;
			if(right.size()!=0)
			{
				if(pos=="left")
					trip++;
				pos="left";
				trip++;
				for(it=right.begin();right.size()!=0;it++)
				{
					amnt+=*it;
					if(amnt>l)
						break;
					else
					{
						//cout<<*it<<endl;
						right.erase(it);
						//cout<<right.size()<<endl;
						//cnt++;
					}
				}
			}
			
			//cout<<trip<<endl;
			//cout<<cnt<<endl;
		}
		cout<<trip<<endl;
	}
    return 0;
}

