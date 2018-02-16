#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
#include<vector>
#include<stdio.h>
#include<bitset>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define FOR(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers
ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 + small extra bits should be enough for most prime-related problems
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0 .. upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.reset(); bs.flip(); // set all numbers to 1
bs.set(0, false); bs.set(1, false); // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i)) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
primes.push_back((int)i); // also add this vector containing list of primes
}
} // call this method in main method
int main()
{
	sieve(1000000); // can go up to 10^7
	int n,l,u,cnt,temp,champ,max;
	map<int,int> data;
	map<int,int>::iterator it3;
	vi::iterator it2;
	cin>>n;
	while(n--)
	{
		max=0;
		data.clear();
		cin>>l>>u;
		vi diff;
		diff.clear();
		vi::iterator it=primes.begin();
		while(*it<l)
		{
			it++;
		}
		for(;it!=primes.end()&&*it<=u;it++)
		{
			it2=it;
			it2++;
			if(it2!=primes.end()&&*it2<=u)
			{
				diff.push_back(*it2-*it);
			}
		}
		if(diff.size()==0)
		{
			cout<<"No jumping champion"<<endl;
			continue;
		}
		for(int i=0;i<diff.size();i++)
		{
			cnt=1;
			it3=data.find(diff[i]);
			if(it3!=data.end())
			{
				continue;
			}
			for(int j=i+1;j<diff.size();j++)
			{
				if(diff[j]==diff[i])
				{
					cnt++;
				}
			}
			data[diff[i]]=cnt;
			if(cnt>max)
			{
				max=cnt;
				champ=diff[i];
			}
		}
		int size=0;
		for(it3=data.begin();it3!=data.end();it3++)
		{
			if(it3->second==max)
			{
				size++;
			}
		}
		if(size>1)
		{
			cout<<"No jumping champion"<<endl;
		}
		else
		{
			cout<<"The jumping champion is "<<champ<<endl;
		}
	}
    return 0;
}

