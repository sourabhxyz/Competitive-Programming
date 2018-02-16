/*Problem statement:
In Takahashi Kingdom, which once existed, there are N cities, and some pairs of cities are 
connected bidirectionally by roads. The following are known about the road network:

People traveled between cities only through roads. It was possible to reach any city 
from any other city, via intermediate cities if necessary.
Different roads may have had different lengths, but all the lengths were positive integers.
Snuke the archeologist found a table with N rows and N columns, A, in the ruin of Takahashi 
Kingdom. He thought that it represented the shortest distances between the cities along the 
roads in the kingdom.
Determine whether there exists a road network such that for each u and v, the 
integer A(u,v) at the u-th row and v-th column of A is equal to the length of the 
shortest path from City u to City v. If such a network exist, find the shortest 
possible total length of the roads.*/	
#include <cstdio>
typedef long long lld;
const int MAXN = 305;
lld graph[MAXN][MAXN]{ };
bool skip[MAXN][MAXN]{ };
lld M, ret=0;
int N;
 
int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	for(int j = 1; j <= N; ++j)
		scanf("%d", &graph[i][j]);
	for(int k = 1; k <= N; ++k)
		for(int i = 1; i <= N; ++i) 
			if(k != i)
				for(int j = 1; j <= N; ++j) 
					if(k != j && i != j)
						if(graph[i][k] + graph[k][j] < graph[i][j])
							return puts("-1"), 0;
						else if(graph[i][k] + graph[k][j] == graph[i][j])
							skip[i][j] = skip[j][i] = true;
	for(int i = 1; i < N; ++i)
	for(int j = i+1; j <= N; ++j)
		if(!skip[i][j]) ret += graph[i][j];
	printf("%lld\n", ret);
	return 0;
}
