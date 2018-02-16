#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<stdio.h>
using namespace std;
struct item{
	string recipe;
	int cost;
};
bool cmp(item i, item j) {
    if(i.cost != j.cost)
        return i.cost < j.cost;
    return i.recipe.compare(j.recipe) < 0;
}
int main()
{
	map<string,int> ingc;
	int t,m,n,b,c,k,amount,costa;
	char ch;
	string ing,title,inga;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		bool exist=false;
		getline(cin,title);
		for(int i=0;i<title.size();i++)
		{
			ch=title[i];
    		putchar(toupper(ch));
		}
		cin>>m>>n>>b;
		while(m--)
		{
			cin.ignore();
			cin>>ing;
			cin>>c;
			ingc[ing]=c;
		}//Now are ingc is done
		cin.ignore();
		string recipe;
		item ans[n];
		for(int i=0;i<n;i++)
		{
			costa=0;
			getline(cin,recipe);
			ans[i].recipe=recipe;
			cin>>k;
			cin.ignore();
			for(int j=0;j<k;j++)
			{
				cin>>inga>>amount;
				costa+=ingc[inga]*amount;
			}
			cin.ignore();
			ans[i].cost=costa;
		}
		sort(ans, ans+n, cmp);
		//cout<<title<<endl;
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			if(ans[i].cost<=b)
			{
				cout<<ans[i].recipe<<endl;
				exist=true;
			}		
		}
		if(!exist)
			cout<<"Too expensive!"<<endl;
		cout<<endl;
	}
    return 0;
}

