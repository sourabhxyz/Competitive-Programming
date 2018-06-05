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