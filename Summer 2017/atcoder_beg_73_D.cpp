/*
Problem description:
There are N towns in the State of Atcoder, connected by M bidirectional roads.
The i-th road connects Town Ai and Bi and has a length of Ci.
Joisino is visiting R towns in the state, r1,r2,..,rR (not necessarily in this order).
She will fly to the first town she visits, and fly back from the last town she visits, 
but for the rest of the trip she will have to travel by road.
If she visits the towns in the order that minimizes the distance traveled by road, what will that distance be?
-------------------
Constraints:
2=N=200
1=M=N×(N-1)/2
2=R=min(8,N) (min(8,N) is the smaller of 8 and N.)
ri!=rj(i!=j)
1<=Ai,Bi<=N,Ai!=Bi
(Ai,Bi)!=(Aj,Bj),(Ai,Bi)!=(Bj,Aj)(i!=j)
1<=Ci<=100000
Every town can be reached from every town by road.
All input values are integers.
-------------------
Input:
Input is given from Standard Input in the following format:

N M R
r1 … rR
A1 B1 C1
:
AM BM CM
-------------------
Output:
Print the distance traveled by road if Joisino visits the towns in the order that minimizes it.
-------------------
Sample Input:
4 6 3
2 3 4
1 2 4
2 3 3
4 3 1
1 4 1
4 2 2
3 1 6
Sample output:
3
-------------------
*/
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

int graph[205][205];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,E,R;
    cin>>V>>E>>R;
    for(int i = 0;i<205;i++)
    {
        for(int j = 0;j<205;j++)
        {
            if(i!=j) graph[i][j]=INF;
            else graph[i][j] = 0;
        }
    }
    vector<int> ToTake;
    for(int i = 0;i<R;i++)
    {
        int tmp;
        cin>>tmp;
        ToTake.push_back(tmp-1);
    }
    for(int i = 0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        if(graph[u][v]>w)
            graph[u][v]=graph[v][u]=w;
    }
    for (int k = 0; k < V; k++) // remember that loop order is k->i->j
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    sort(ToTake.begin(),ToTake.end());
    int res = INF;
    do{
        int tmp = 0;
		for (int i = 0; i < ToTake.size()-1; ++i)
			tmp += graph[ToTake[i]][ToTake[i + 1]];
		res = min(res, tmp);
	}while(next_permutation(ToTake.begin(), ToTake.end()));
	cout<<res<<"\n";
    return 0;
}

