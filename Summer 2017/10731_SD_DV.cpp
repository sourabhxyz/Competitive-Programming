/*Nothing new as such, just see line 43 49 99 101 105 106*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string, int> msi;
typedef map<int,pair<int,int> > miii;
#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 50000000
#define maxN 10000010
#define VISITED 1
#define UNVISITED -1
vector<vector<int> >  AdjList;
vector<vector<char> > ans;
int dfsNumberCounter,numSCC,k=-1;
char c;
bool arr[26];
vi dfs_num, dfs_low, S, visited; // global variables
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v]) // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
            k++; ///CONCEPT
        //cout<<"SCC "<<++numSCC; // this part is done after recursion
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            c=65+v;
            //cout<<" "<<c;
            ans[k].push_back(c); ///CONCEPT
            if (u == v) break;
        }
        //printf("\n");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V=26,n,u,v;
    string line;
    bool first=true;
    while(cin>>n&&n)
    {
        if(first)
            first=false;
        else  cout<<"\n";
        k=-1;
        memset(arr,0,sizeof arr);
        cin.ignore();
        ans.clear();
        ans.resize(26);
        AdjList.clear();
        AdjList.resize(26);
        for(int i=0;i<n;i++)
        {
            getline(cin,line);
            u=line[line.size()-1]-'A';
            arr[u]=true;
            line.pop_back();
            line.pop_back();
            while(line.size()>0)
            {
                v=line[line.size()-1]-'A';
                arr[v]=true;
                if(u!=v)
                {
                    AdjList[u].push_back(v);
                }
                line.pop_back();
                if(line.size()>0)
                line.pop_back();
            }
        }
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        for (int i = 0; i < V; i++)
            if (arr[i]&&dfs_num[i] == UNVISITED) ///CONCEPT
                tarjanSCC(i);
        for(int i=0;i<=k;i++) ///CONCEPT
        {
            sort(ans[i].begin(),ans[i].end());
        }
        ans.resize(k+1); ///CONCEPT
        sort(ans.begin(),ans.end());  ///CONCEPT
        for(int i=0;i<=k;i++)
        {
            cout<<ans[i][0];
            for(int j=1;j<ans[i].size();j++)
            {
                cout<<" "<<ans[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
