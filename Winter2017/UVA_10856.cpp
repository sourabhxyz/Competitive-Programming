#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i); // add this prime to the list of primes
        } } // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
    if (N <= _sieve_size) return bs[N]; // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2

int primeFactors(ll N) { // remember: vi is vector<int>, ll is long long
    int cnt = 0;
    int PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
    while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
        while (N % PF == 0) { N /= PF; cnt++;} // remove PF
        PF = primes[++PF_idx]; // only consider primes!
    }
    if (N != 1) cnt++; // special case if N is a prime
    return cnt; // if N does not fit in 32-bit integer and is a prime
} // then ‘factors’ will have to be changed to vector<ll>

map<ll, ll> data;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    ll n;
    sieve(10000);
    ll totalcnt = 0;
    for(ll i = 2; i <= 2703665; i++) {
        int cnt = primeFactors(i);
        totalcnt += cnt;
        data[totalcnt] = i;
    }
    int cno = 1;
    while(cin >> n and n >= 0) {
        cout << "Case " << cno++ << ": ";
        if(n == 0) cout << "0!\n";
        else if(data.find(n) != data.end()) cout << data[n] << "!\n";
        else cout << "Not possible.\n";
    }

    return 0;
}
