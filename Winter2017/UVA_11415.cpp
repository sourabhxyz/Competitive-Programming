#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(int upperbound) { // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (int i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
            for (int j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back(i); // add this prime to the list of primes
        } } // call this method in main method

inline int primeFactors(int N) { // remember: vi is vector<int>, ll is long long
    int cnt = 0;
    int PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
    while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
        while (N % PF == 0) { N /= PF; cnt++;} // remove PF
        PF = primes[++PF_idx]; // only consider primes!
    }
    if (N != 1) cnt++; // special case if N is a prime
    return cnt; // if N does not fit in 32-bit integer and is a prime
} // then ‘factors’ will have to be changed to vector<ll>

int cnt[2703666];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("ina.txt", "r", stdin);
//    freopen("outa.txt", "w", stdout);
    int n;
    sieve(10000);
    cnt[0] = 1;
    cnt[1] = 1;
    cnt[2] = 1;
    int totalcnt = 1;
    for(int i = 3; i <= 2703665; i++) {
        int icnt = primeFactors(i);
        totalcnt += icnt;
        cnt[i] = totalcnt;
    }
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 0;
        for(int i = 0; ; i++) {
            if(cnt[i] <= n) ans++;
            else break;
        }
        cout << ans << "\n";
    }
    return 0;
}
