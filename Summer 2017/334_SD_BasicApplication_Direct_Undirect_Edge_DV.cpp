
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
bool nodes[200+5][200+5];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int nc,cases=0,n,nm,vertno,cnt;
    string line,line2;
    map<string,int> data;
    vector<string> getback;
    vector<string> ans;
    while(cin>>nc&&nc)
    {
        cases++;
        ans.clear();
        getback.clear();
        memset(nodes,0,sizeof nodes);
        cnt=0;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                graph[i][j]=0;
            }
        }
        vertno=0;
        data.clear();
        for(int i=0;i<nc;i++)
        {
            cin>>n;
            int arr[n];
            for(int j=0;j<n;j++)
            {
                cin>>line;
                if(data.find(line)==data.end())
                {
                    data[line]=vertno;
                    getback.push_back(line);
                    vertno++;
                }
                arr[j]=data[line];
            }
            for(int j=0;j<n-1;j++)
            {
                graph[arr[j]][arr[j+1]]=1;
            }
        }
        cin>>nm;
        for(int i=0;i<nm;i++)
        {
            cin>>line>>line2;
            graph[data[line]][data[line2]]=1;
        }
        for (int k = 0; k < vertno; k++)
            for (int i = 0; i < vertno; i++)
                for (int j = 0; j < vertno; j++)
                    graph[i][j] |= (graph[i][k] & graph[k][j]);
        for(int i=0;i<vertno;i++)
        {
            for(int j=0;j<vertno;j++)
            {
                if(graph[i][j]==0&&graph[j][i]==0&&!nodes[i][j]&&i!=j)
                {
                    cnt++;
                    nodes[i][j]=true;
                    nodes[j][i]=true;
                    if(cnt<=2)
                    {
                        ans.push_back(getback[i]);
                        ans.push_back(getback[j]);
                    }
                }
            }
        }
        if(cnt!=0)
        {
            cout<<"Case "<<cases<<", "<<cnt<<" concurrent events:\n";
            if(ans.size()>2)
            {
                cout<<"("<<ans[0]<<","<<ans[1]<<") ("<<ans[2]<<","<<ans[3]<<") \n";
            }
            else cout<<"("<<ans[0]<<","<<ans[1]<<") \n";

        }
        else
            cout<<"Case "<<cases<<", no concurrent events.\n";
    }
    return 0;
}

