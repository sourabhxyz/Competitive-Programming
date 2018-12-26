/* n rotational axis and n axis of symmetry 
   for rotation: rotation by 0 cells, by 1 cell, by 2 cells, etc, by (n-1) cells
   Now let's apply the lemma, and find the number of stripes that are fixed by the rotation by K cells. If a stripe becomes itself after rotating by K cells, then its 1st cell must have the same color as its (1+K modulo n)-th cell, which is in turn the same as its (1+2K modulo n)-th cell, etc, until we get back to the 1st cell when m*K modulo n=0. One may notice that this will happen when m=n/gcd(K,n), thus these must have same color. and we independent choice for n/(n/gcd(K, n)) = gcd(K, n).
   for axis of symmetry:
    if (n is even) then we have 
      (n/2) axis of symmetry which pass through 2 elements, and for those 2 elements we have independent choice => 3^2 and for remaining, we get a pair, i.e. 3^((n - 2)/2). Thus total is 3^((n + 2)/2)
      (n/2) axis of symmetry which passes through non of the elements and again we get a pair, thus 3^(n/2) 
    if (n is odd) then all n axis of symmetry pass through a single element and we get independent choice for that one element, and for others we get pair i.e. 3 * 3^((n - 1)/2)
   
   */

#include <iostream>
#include <algorithm>

const int MAXN = 24;

unsigned long long ans[MAXN];

unsigned long long int_pow(unsigned long long v, int p) {
  unsigned long long res = 1;
  for (int i = p; i; i >>= 1) {
    if (i & 1) res *= v;
    v *= v;
  }
  return res;
}

unsigned long long solve(int n) {
  if (n == 0 || ans[n]) return ans[n];
  for (int i = 1; i <= n; ++i) { // for (int i = 0; i < n; i++)
    ans[n] += int_pow(3, std::__gcd(i, n));
  }
  if (n & 1) {
    ans[n] += int_pow(3, n / 2 + 1) * n; // (3 ^ ((n - 1) / 2) * 3) == (3 ^ ((n + 1) / 2))
  } else {
    ans[n] += int_pow(3, n / 2 + 1) * (n / 2);
    ans[n] += int_pow(3, n / 2) * (n / 2);
  }
  return ans[n] /= n * 2;
}

signed main() {
  std::ios::sync_with_stdio(false);
  int n;
  while (std::cin >> n && ~n) {
    std::cout << solve(n) << std::endl;
  }
  return 0;
}