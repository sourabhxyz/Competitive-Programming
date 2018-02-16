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
#include<cstdio>
#include<cmath>
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
vector<int> prime;
ll _sieve_size,lm; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 + small extra bits should be enough for most prime-related problems
void sieve(ll upperbound) { // create list of primes in [0 .. upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.reset(); bs.flip(); // set all numbers to 1
bs.set(0, false); bs.set(1, false); // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i)) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
prime.push_back((int)i); // also add this vector containing list of primes
}
}
bool isPrime(unsigned long long int n) {
    if (n < _sieve_size) return bs.test(n);
    for (int i=0, lm=(int)sqrt(n); i<prime.size() && prime[i]<=lm; i++)
        if (n%prime[i]==0) return false;
    return true;
}
int main()
{
	sieve(1000000); // can go up to 10^7
	int n;
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	bool flag;
	vi::iterator it;
    while(scanf("%d", &n) && n){//see photo 2
    	printf("%d:\n",n);
    	flag=false;
        for(it=prime.begin();*it<=n/2;it++){//Here since we were strictly given odd numbers pair, 
        // we are beginning with primes.begin()+1 but since it is true for 4, meaning 2+2.
                int b = n-*it;
                if(isPrime(b)){
                    printf("%d+%d\n",*it, b);
                    flag=true;
                    break;
                }
 
            }
            if(flag==false)
            printf("NO WAY!\n");
        }
    return 0;
}

