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
typedef map<int,pair<int,int> > miii;
typedef complex<double> point;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<vi > vvi;
#define X real()
#define Y imag()
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
#define VISITED 1
#define UNVISITED -1
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define MAX_W 1010
#define MAX_N 40

int i, t, w_,G, ans, N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];
bool taken[MAX_N][MAX_W];

int value(int id, int w) {
  if (id == N || w == 0) return 0;
  if (memo[id][w] != -1) return memo[id][w];
  int a = (W[id]> w ) ? 0 : V[id]+value(id+1,w-W[id]);
  int b = value(id+1,w);
  taken[id][w]= a>b;
  return memo[id][w]=max(a,b);
}

int main() {
    bool first = true;
  while (scanf("%d %d",&t,&w_)==2) {
    if(first) first=false;
    else printf("\n");
    memset(memo, -1, sizeof memo);
    memset(taken,0,sizeof taken);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
      scanf("%d %d",&W[i],&V[i]);
      W[i]*=3*w_;
    }

      vi track;
      ans = value(0, t);
      printf("%d\n", ans);
      i=0;
      int j=t;
      int cnt=0;
      while(i<N)
      {
          if(taken[i][j])
          {
              track.push_back(i);
              cnt++;
              j=j-W[i];
          }
          i++;
      }
      printf("%d\n",cnt);
      for(i=0;i<track.size();i++)
      {
          printf("%d %d\n",W[track[i]]/3/w_,V[track[i]]);
      }
  }

  return 0;
}

/*

// 0-1 Knapsack DP (Bottom-Up)

#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_N 1010
#define MAX_W 40

int i, w, T, N, G, MW, V[MAX_N], W[MAX_N], C[MAX_N][MAX_W], ans;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (i = 1; i<= N; i++)
      scanf("%d %d", &V[i], &W[i]);

    ans = 0;
    scanf("%d", &G);
    while (G--) {
      scanf("%d", &MW);

      for (i = 0; i <= N;  i++) C[i][0] = 0;
      for (w = 0; w <= MW; w++) C[0][w] = 0;

      for (i = 1; i <= N; i++)
        for (w = 1; w <= MW; w++) {
          if (W[i] > w) C[i][w] = C[i - 1][w];
          else          C[i][w] = max(C[i - 1][w], V[i] + C[i - 1][w - W[i]]);
        }

      ans += C[N][MW];
    }

    printf("%d\n", ans);
  }

  return 0;
}

*/

