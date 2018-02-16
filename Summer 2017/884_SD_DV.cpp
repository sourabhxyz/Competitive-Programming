#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string, int> msi;
typedef map<int,pair<int,int>> miii;
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 10000010

vector<int> prime;
ll _sieve_size,lm; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 + small extra bits should be enough for most prime-related problems
void sieve(ll upperbound)
{ // create list of primes in [0 .. upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.reset(); bs.flip(); // set all numbers to 1
    bs.set(0, false); bs.set(1, false); // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i))
    {
    // cross out multiples of i starting from i * i!
        for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
        prime.push_back((int)i); // also add this vector containing list of primes
    }
}
bool isPrime(unsigned long long int n)
{
    if (n < _sieve_size) return bs.test(n);
    for (int i=0, lm=(int)sqrt(n); i<prime.size() && prime[i]<=lm; i++)
        if (n%prime[i]==0) return false;
    return true;
}
int primeFactorscnt(unsigned long long int N)
{
    int cnt =0;
    unsigned long long int PF_idx = 0, PF = prime[PF_idx]; // using PF = 2, 3, 4, ..., is also ok.
    while (N != 1 && (PF * PF <= N))
    { // stop at sqrt(N), but N can get smaller
        while (N % PF == 0)
        {
            cnt++;
            N /= PF;
        } // remove this PF
        PF = prime[++PF_idx];
    }
    if (N != 1) cnt++; // special case if N is actually a prime
    return cnt;
}
int data[1000002];
int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    sieve(1000010);
    int n,pre=0;
    for(int i=2;i<=1000000;i++)
    {
        pre+=primeFactorscnt(i);
        data[i]=pre;
    }
    while(cin>>n)
    {
        cout<<data[n]<<"\n";
    }
    return 0;
}

