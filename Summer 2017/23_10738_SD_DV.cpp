#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<set>
#include<bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 10000010
int mu[1000001];
int M[1000001];
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
int sqfree(int N) {
int PF_idx = 0, PF = prime[PF_idx],t,cnt=0; // using PF = 2, 3, 4, ..., is also ok.
while (N != 1 && (PF * PF <= N)) { 
t=0; 
while (N % PF == 0) { cnt++; N /= PF; t++; if(t==2) {return 0;} } // remove this PF
PF = prime[++PF_idx]; 
}
if (N != 1) cnt++; // special case if N is actually a prime
return cnt;
}
int main() 
{
	sieve(1000000); // can go up to 10^7
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int temp,n;
    mu[1]=1;
    M[1]=1;
    for(int i=2;i<1000001;i++)
    {
    	if(isPrime(i))
    	{
    		mu[i]=-1;
		}
		else
		{
			temp=sqfree(i);
			if(temp==0)
			{
				mu[i]=0;
			}
			else if(temp%2==0)
			{
				mu[i]=1;
			}
			else
			{
				mu[i]=-1;
			}
		}
		M[i]=M[i-1]+mu[i];
	}
	while(scanf("%d",&n)&&n)
	{
		printf("%8d%8d%8d\n", n, mu[n], M[n]);
	}
	return 0;
}
