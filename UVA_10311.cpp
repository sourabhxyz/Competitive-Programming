#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<100000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= 100000000; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i); // add this prime to the list of primes
        } } // call this method in main method
bool isPrime(int N) { // a good enough deterministic prime tester
    if (N <= _sieve_size) return bs[N]; // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(1);
    sieve(100000000LL);
    int n;
    while(cin >> n) {
        if(n < 4) {
            cout << n << " is not the sum of two primes!\n";
            continue;
        }
        if(n & 1) {
            if(isPrime((n - 2))) {
                cout << n << " is the sum of 2 and " << n - 2 << ".\n";
            }
            else {
                cout << n << " is not the sum of two primes!\n";
            }
            continue;
        }
        int a = 0, b = 0;
        auto it = upper_bound(primes.begin(), primes.end(), n / 2);
        int pos = it - primes.begin();
        for(int i = pos; i >= 0; i--) {
            if(isPrime((n - primes[i])) and n - primes[i] > primes[i]) {
                a = primes[i]; b = n - primes[i];
                break;
            }
        }
        if(a) {
            cout << n << " is the sum of " << a << " and " << b << ".\n";
        }
        else {
            cout << n << " is not the sum of two primes!\n";
        }
    }
    return 0;

}
