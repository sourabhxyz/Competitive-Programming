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
vector< viii > AdjList;
map<string,int> data;
map<string,int>::iterator it;
vector<vector<bool > > visited;
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
   // FileIn("in");
   // FileOut("out");
    string s_,end_,u_,v_,word;

    int V,sletter,E,ans;
    while(cin>>E&&E)
    {
        data.clear();
        AdjList.clear();
        AdjList.resize(5000);//it is actually greater than 2000 but less than 5000.
        cin>>s_;
        cin>>end_;
        //getline(cin,s_);
        //getline(cin,end_);
        data[s_]=0;
        data[end_]=1;
        int k=2;
        for(int i=0;i<E;i++)
        {
            cin>>u_>>v_>>word;
            it=data.find(u_);
            if(it==data.end())
            {
                data[u_]=k;
                k++;
            }
            it=data.find(v_);
            if(it==data.end())
            {
                data[v_]=k;
                k++;
            }
            sletter=word[0]-'a';
            AdjList[data[u_]].push_back(make_pair(data[v_],ii(word.length(),sletter)));
            AdjList[data[v_]].push_back(make_pair(data[u_],ii(word.length(),sletter)));
        }
        /*cout<<k<<"\n";
        for(it=data.begin();it!=data.end();it++)
            cout<<it->first<<" "<<it->second<<"\n";*/
        vector<vector<int> > dist;// dist[0] = 0; /// INF = 1B to avoid overflow
        dist.resize(k);
        visited.resize(k);
        for(int i=0;i<k;i++)
        {
            dist[i].assign(27,INF);
            visited[i].assign(27,false);
        }
        priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push(make_pair(0,ii(data[s_], 27))); ///Note: this greater<ii> and vector<ii> is
        ///is used to store elements in the increasing order instead of decreasing order.
        dist[0][27]=0;
        ans=INF;
        while (!pq.empty()) { /// main loop
            iii front = pq.top(); pq.pop(); /// greedy: get shortest unvisited vertex
            if(visited[front.second.first][front.second.second]) continue;
            visited[front.second.first][front.second.second]=true;
            int d = front.first;
            ii u=front.second;
            if(u.first==1) { ans = dist[1][u.second]; break; }
            //if (d > dist[u.first]) continue; /// this is a very important check
            for (int j = 0; j < (int)AdjList[u.first].size(); j++) {
                iii v = AdjList[u.first][j]; /// all outgoing edges from u
                if(v.second.second!=u.second)
                {
                    if (dist[u.first][u.second] + v.second.first< dist[v.first][v.second.second]) {
                        dist[v.first][v.second.second] = dist[u.first][u.second] + v.second.first; /// relax operation
                        pq.push(make_pair(dist[v.first][v.second.second],ii(v.first, v.second.second)));
                    }
                }

            }

        }

        if(ans!=INF)
        cout<<ans<<"\n";
        else
            cout<<"impossivel\n";
    }
    return 0;
}

