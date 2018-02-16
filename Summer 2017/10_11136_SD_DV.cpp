#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>

using namespace std;

int main()
{
	int n,day,temp;
	unsigned long long paid;
	multiset<int> data;
	multiset<int>::iterator it;
	multiset<int>::iterator it2;
	while(cin>>n&&n){
		paid=0;
		while(n--)
		{
			cin>>day;
			for(int i=0;i<day;i++)
			{
				cin>>temp;
				data.insert(temp);
			}
			it=data.end();
			it--;
			it2=data.begin();
			paid+=*it-*it2;
			data.erase(it);
			data.erase(it2);
		}
		cout<<paid<<endl;
		data.clear();
	}
    return 0;
}

