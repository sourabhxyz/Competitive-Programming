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
vi primes; 
void sieve(ll upperbound) { 
primes.push_back(1);// create list of primes in [0 .. upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.reset(); bs.flip(); // set all numbers to 1
bs.set(0, false); bs.set(1, false); // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i)) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
primes.push_back((int)i); // also add this vector containing list of primes
}
} // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N < _sieve_size) return bs.test(N); // O(1) for small primes
FOR (i, 0, primes.size() - 1) if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // Note: only work for N <= (last prime in vi "primes")^2
int main()
{
	sieve(1000); // can go up to 10^7
	int n,c,cnt;
	vi::iterator it;
	while(cin>>n>>c)
	{
		cnt=1;
		it=primes.begin();
		vector<int> ans;
		ans.clear();
		printf("%d %d:",n,c);
		while(*it<=n&&it!=primes.end())
		{
			ans.push_back(*it);
			it++;
		}
		if(ans.size()%2==0)
		{
			if(2*c>ans.size())
			{
				for(it=ans.begin();it!=ans.end();it++)
				{
					cout<<" "<<*it;
				}
			}
			else
			{
				for(it=ans.begin()+ans.size()/2 -c;cnt<=2*c;it++)
				{
					cout<<" "<<*it;
					cnt++;
				}
			}
		}
		else
		{
			if(2*c-1>ans.size())
			{
				for(it=ans.begin();it!=ans.end();it++)
				{
					cout<<" "<<*it;
				}
			}
			else
			{
				for(it=ans.begin()+ans.size()/2 -c+1;cnt<=2*c-1;it++)
				{
					cout<<" "<<*it;
					cnt++;
				}
			}
		}
		cout<<endl<<endl;
	}
    return 0;
}

