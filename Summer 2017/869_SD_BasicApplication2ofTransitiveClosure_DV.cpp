
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
int graph[200+5][200+5];
int graph2[205][205];
void init()
{
    for(int i=0;i<200;i++)
    {
        for(int j=0;j<200;j++)
        {
            graph[i][j]=0;
            graph2[i][j]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    FileIn("in");
    FileOut("out");
    int cases,E,nodes1,nodes2,k=0;
    map<char,int> data,data2;
    cin>>cases;
    char c,c2;
    bool check1,check2;
    while(cases--)
    {
        if(k>0) cout<<"\n";
        k++;
        check1=true;
        check2=true;
        data.clear();
        data2.clear();
        init();
        nodes1=0;
        nodes2=0;
        cin>>E;
        for(int i=0;i<E;i++)
        {
            cin>>c;
            if(data.find(c)==data.end())
            {
                data[c]=nodes1;
                nodes1++;
            }
            cin>>c2;
            if(data.find(c2)==data.end())
            {
                data[c2]=nodes1;
                nodes1++;
            }
            graph[data[c]][data[c2]]=1;

        }
        cin>>E;
        for(int i=0;i<E;i++)
        {
            cin>>c;
            if(data2.find(c)==data2.end())
            {
                data2[c]=nodes2;
                nodes2++;
            }
            cin>>c2;
            if(data2.find(c2)==data2.end())
            {
                data2[c2]=nodes2;
                nodes2++;
            }
            graph2[data2[c]][data2[c2]]=1;

        }
        if(nodes1!=nodes2)
        {
            cout<<"NO\n";
            continue;
        }
        for (int k = 0; k < nodes1; k++)
            for (int i = 0; i < nodes1; i++)
                for (int j = 0; j < nodes1; j++)
                {
                    graph[i][j] |= (graph[i][k] & graph[k][j]);
                    graph2[i][j] |= (graph2[i][k] & graph2[k][j]);
                }
        for(int i=0;i<nodes1&&check1&&check2;i++)
        {
            for(int j=0;j<nodes1&&check1&&check2;j++)
            {
                if(i!=j&&(graph[i][j]==1||graph[i][j]==1))
                {
                    if(graph2[i][j]==1||graph2[j][i]==1)
                        continue;
                    else check1=false;
                }
                if(i!=j&&(graph2[i][j]==1||graph2[i][j]==1))
                {
                    if(graph[i][j]==1||graph[j][i]==1)
                        continue;
                    else check2=false;
                }
            }
        }
        if(check1&&check2)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
}


