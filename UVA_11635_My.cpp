#include<bits/stdc++.h>

using namespace std;

#define INF 100000000

struct node {
  int days, vertex, minutesRemaining;
  node () {}
  node (int n, int d, int r) {
    vertex = n; days = d, minutesRemaining = r;
  }
  bool operator < (const node &node) const {
    if (days != node.days) return days > node.days;
    if (minutesRemaining != node.minutesRemaining) return minutesRemaining < node.minutesRemaining;  // this is actually important optimization.
    return vertex > node.vertex;
  }
};

int main () {
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
  int n;
  bool ok;
  while (cin >> n && n) {
    ok = false;
    set<int> hotels;
    int h;
    cin >> h;
    for (int i = 0; i < h; i++) {
      int temp;
      cin >> temp;
      hotels.insert(temp - 1);
    }
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> adjList(n);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adjList[u - 1].push_back(pair<int, int>(v - 1, w));
      adjList[v - 1].push_back(pair<int, int>(u - 1, w));
    }
    vector<vector<int>> daysV (n, vector<int>(601, INF));
    daysV[0][600] = 0;
    priority_queue<node> pq;
    pq.push (node (0, 0, 600));
    while (!pq.empty ()) {
      int from, to, wt, days, minutesRemaining;
      from = pq.top ().vertex;
      // cout << from << "\n";
      days = pq.top ().days;
      minutesRemaining = pq.top ().minutesRemaining;
      pq.pop ();
      if (from == n - 1) {
        ok = true;
        cout << daysV[n - 1][minutesRemaining] << "\n";
        break;
      }
      if (days == daysV[from][minutesRemaining]) {  // lazily deleting
        for (int i = 0; i < adjList[from].size (); i++) {
          to = adjList[from][i].first;
          wt = adjList[from][i].second;
          if (minutesRemaining >= wt) {  // can go there
            if (daysV[to][minutesRemaining - wt] > daysV[from][minutesRemaining]) {  // else not worth it
              daysV[to][minutesRemaining - wt] = days;
              pq.push (node (to, days, minutesRemaining - wt));
            }
            if (hotels.count(to)) {  // can stay there
              if (daysV[to][600] > days + 1) {
                daysV[to][600] = days + 1;
                pq.push (node (to, daysV[to][600], 600));
              }    
            }
          }
        }
      }
    }
    if (!ok) cout << "-1\n";
  }
  return 0;
}
