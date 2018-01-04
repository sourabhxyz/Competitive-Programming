#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000

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

ll numDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
    while (PF * PF <= N) {
        ll power = 0; // count the power
        while (N % PF == 0) { N /= PF; power++; }
        ans *= (power + 1); // according to the formula
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
    return ans;
}

ll EulerPhi(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N; // start from ans = N
    while (PF * PF <= N) {
        if (N % PF == 0) ans -= ans / PF; // only count unique factor
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) ans -= ans / N; // last factor
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(1);
    sieve(100000LL);
    ll n;
    while(cin >> n) {
        if(n <= 2) {
            cout << "0\n";
            continue;
        }
        cout << n - EulerPhi(n) - numDiv(n) + 1 << "\n";
    }
    return 0;

}
