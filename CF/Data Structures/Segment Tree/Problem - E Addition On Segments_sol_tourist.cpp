/**
 *    author:  tourist
 *    created: 27.05.2018 18:09:26       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> st(4 * n + 100);
  function<void(int,int,int,int,int,int)> modify = [&](int x, int l, int r, int ll, int rr, int v) {
    if (r < ll || rr < l) { // if outside range
      return;
    }
    if (ll <= l && r <= rr) { // if inside range
      st[x].push_back(v); // we are doing parent push_back(update_val), it is evident that only these 
      // nodes are getting modified and not their parents, maybe because we want to consider each range
      // seperately as each node corresponds to unique range...
      return;
    }
    int y = (l + r) >> 1; 
    // we should do modify(left(x), l, y, ll, rr, v) and modify(right(x), y + 1, r, ll, rr, v)
    // but if mid is >= ll that means there is an intersection between [l, y] and [ll, rr]
    // note that the other case of intersection, which is l >= ll and l <= rr and y > rr also implies
    // that y >= ll.
    // but it does not imply that there is an intersection between [y + 1, r] and [ll, rr]
    // we can see that [y + 1, r] and [ll, rr] will have intersection if (y + 1 <= ll and r >= ll, r >=
    // ll is already satisfied by above constraints, so this condition reduces to y + 1 <= ll and this
    // is covered in saying y + 1 <= rr i.e. rr > y) or 
    // (y + 1 > ll and r <= rr) (but this is not possible due to above condition)
    //  or (y + 1 > ll and y + 1 <= rr) this is also covered in rr >= y + 1 or rr > y
    if (ll <= y) {
      modify(x + x, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(x + x + 1, y + 1, r, ll, rr, v);
    }
  };
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--; r--;
    modify(1, 0, n - 1, l, r, x);
  }
  bitset<N> ans;
  function<void(int,int,int,bitset<N>)> solve = [&](int x, int l, int r, bitset<N> b) {
    for (int v : st[x]) {
      b |= (b << v); // crux
    }
    if (l == r) {
      ans |= b; // seemingly, ans gets modified only at leaves.
      return;
    }
    int y = (l + r) >> 1;
    solve(x + x, l, y, b);
    solve(x + x + 1, y + 1, r, b);
  };
  bitset<N> b; // all bits are initially 0
  b.set(0); // setting the zeroth bit.
  solve(1, 0, n - 1, b);
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 1) {
      res.push_back(i);
    }
  }
  int sz = (int) res.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}