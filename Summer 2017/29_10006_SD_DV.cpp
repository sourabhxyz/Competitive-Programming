#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using ll = long long;
using llu = unsigned long long;
const int INF = numeric_limits<int>::max();

ll bigmod(ll base, ll pow, ll mod) {//using the bigmod algorithm: its concept is (a*b)%m==((a%m)*(b%m))%m
  if (pow == 0) return 1;
  if (pow % 2 == 0) {
    ll t = bigmod(base, pow / 2, mod);
    return ((t%mod) * (t%mod)) % mod;
  }
  return ((base%mod) * bigmod(base, pow - 1, mod)) % mod;
}
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

int main() {
  sieve(65000);
  ll n,i;
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while (cin >>n&&n) {
  	if(!isPrime(n))
  	{
  		for(i=2;i<=n-1;i++)
  		{
  			if(bigmod(i,n,n)==i)
  			continue;
  			break;
		}
		if(i==n)
		{
			printf("The number %lld is a Carmichael number.\n",n);
		}
		else 
		printf("%lld is normal.\n",n);
	}
	else
	{
		printf("%lld is normal.\n",n);
	}
    
  }
  return 0;
}
