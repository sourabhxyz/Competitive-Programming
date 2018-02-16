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
vector<viii> AdjList;
int t[5];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int V,e,b,del,n,k,s_=0,numbers[100],temp;
    string line;
    while(cin>>n>>k)
    {
        AdjList.clear();
        AdjList.resize(100);
        for(int i=0;i<n;i++)
            cin>>t[i];
        cin.ignore();
        for(int i=0;i<n;i++)
        {
            getline(cin,line);
            stringstream strm;
            strm<<line;
            temp=0;
            while(strm>>numbers[temp])
            {
                temp++;
            }
            for(int j=0;j<temp-1;j++)
            {
                for(int l=j+1;l<temp;l++)
                {
                    AdjList[numbers[j]].push_back(make_pair(numbers[l],ii((numbers[l]-numbers[j])*t[i],i)));
                    AdjList[numbers[l]].push_back(make_pair(numbers[j],ii((numbers[l]-numbers[j])*t[i],i)));
                    ///cout<<(numbers[l]-numbers[j])*t[i]<<"\n";
                }
            }
        }
        vi dist(100, INF); dist[s_] = 0; /// INF = 1B to avoid overflow
        for(int i=0;i<n;i++)
        {
        priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push(make_pair(0,ii(s_, i))); ///Note: this greater<ii> and vector<ii> is
        ///is used to store elements in the increasing order instead of decreasing order.
        while (!pq.empty()) { /// main loop
            iii front = pq.top(); pq.pop(); /// greedy: get shortest unvisited vertex
            int d = front.first;
            ii u=front.second;
            if (d > dist[u.first]) continue; /// this is a very important check
            for (int j = 0; j < (int)AdjList[u.first].size(); j++) {
                iii v = AdjList[u.first][j]; /// all outgoing edges from u
                if(v.second.second!=u.second)
                {
                    if (dist[u.first] + v.second.first +60< dist[v.first]) {
                        dist[v.first] = dist[u.first] + v.second.first+60; /// relax operation
                        pq.push(make_pair(dist[v.first],ii(v.first, v.second.second)));
                    }   /// this variant can cause duplicate items in the priority queue
                }
                else
                {
                    if (dist[u.first] + v.second.first< dist[v.first]) {
                        dist[v.first] = dist[u.first] + v.second.first; /// relax operation
                        pq.push(make_pair(dist[v.first],ii(v.first, v.second.second)));
                    }
                }
            }

        }
        }
        if(dist[k]!=INF)
        cout<<dist[k]<<"\n";
        else
            cout<<"IMPOSSIBLE\n";
        //for(int l=0;l<20;l++)
        //cout<<dist[l]<<"\n";
    }
    return 0;
}
