
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
typedef pair<int,pair<int,char> > iic;
typedef vector<iic> viic;
typedef pair<int,char> ic;
typedef pair<int,pair<string, bool> > isb;
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
int graph[105][105];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int a,b,V,cases=0;
    llu sum;
    map<int,int> cnt;
    while(cin>>a>>b&&(a||b))
    {
        cases++;
        sum=0;
        V=0;
        cnt.clear();
        //memset(graph,500000,sizeof graph);
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                graph[i][j]=INF;

        graph[a-1][b-1]=1;
        if(cnt.find(a-1)==cnt.end())
        {
            cnt[a-1]=1;
            V++;
        }
        if(cnt.find(b-1)==cnt.end())
        {
            cnt[b-1]=1;
            V++;
        }
        while(cin>>a>>b&&(a||b))
        {
            graph[a-1][b-1]=1;
            if(cnt.find(a-1)==cnt.end())
            {
                cnt[a-1]=1;
                V++;
            }
            if(cnt.find(b-1)==cnt.end())
            {
                cnt[b-1]=1;
                V++;
            }
        }
        //cout<<V<<"\n";
        for (int k = 0; k < 100; k++) // remember that loop order is k->i->j
            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        //cout<<graph[0][1]<<" "<<graph[0][2]<<" "<<graph[0][3]<<" ";
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                if(graph[i][j]!=INF&&i!=j)
                    sum+=graph[i][j];
            }
        }
        //cout<<sum<<"\n";
        cout<<"Case "<<cases<<": average length between pages = "<<fixed<<setprecision(3)<<double(sum)/V/(V-1)<<" clicks\n";

    }
    return 0;
}


