
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
int graphy[31][31];
int graphm[31][31];
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int E,energy,mini,s_,e_;
    char a,b,c,d;
    map<char,int> conv;
    map<char,int>::iterator it;
    vector<char> ans;
    for(int i=65,k=0;i<=90;i++,k++)
        conv[i]=k;
    while(cin>>E&&E)
    {
        ans.clear();
        mini=INF;
        for(int i=0;i<27;i++)
            for(int j=0;j<27;j++)
            {
            	if(i==j) { ///pay attention to this
            		graphy[i][j]=0;
            		graphm[i][j]=0;
				}
				else {
                	graphy[i][j]=INF;
                	graphm[i][j]=INF;
                }
            }
        for(int i=0;i<E;i++)
        {
            cin>>a>>b>>c>>d>>energy;
            if(c==d) continue;
            if(a=='Y')
            {
                if(b=='U')
                {
                    graphy[conv[c]][conv[d]]=min(graphy[conv[c]][conv[d]],energy);
                }
                else
                {
                	graphy[conv[c]][conv[d]]=min(graphy[conv[c]][conv[d]],energy);
                    graphy[conv[d]][conv[c]]=min(graphy[conv[d]][conv[c]],energy);
                }
            }
            else
            {
                if(b=='U')
                {
                    //graphy[conv[c]][conv[d]]=min(graphy[conv[c]][conv[d]],energy);
                    graphm[conv[c]][conv[d]]=min(graphm[conv[c]][conv[d]],energy);
                }
                else
                {
                	//graphy[conv[c]][conv[d]]=min(graphy[conv[c]][conv[d]],energy);
                    graphm[conv[c]][conv[d]]=min(graphm[conv[c]][conv[d]],energy);
                    //graphy[conv[d]][conv[c]]=min(graphy[conv[d]][conv[c]],energy);
                    graphm[conv[d]][conv[c]]=min(graphm[conv[d]][conv[c]],energy);
                }
            }
        }
        for (int k = 0; k < 26; k++) // remember that loop order is k->i->j
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    graphy[i][j] = min(graphy[i][j], graphy[i][k] + graphy[k][j]);
        for (int k = 0; k < 26; k++) // remember that loop order is k->i->j
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    graphm[i][j] = min(graphm[i][j], graphm[i][k] + graphm[k][j]);
        cin>>a>>b;
        s_=conv[a];
        e_=conv[b];
        /*if(a==b) We should not use this loop because energy of some edge could be
        		//zero as well...
        {
        	cout<<"0 "<<a<<"\n";
        	continue;
		}*/
        for(int i=0;i<26;i++)
        {
            if(graphy[s_][i]!=INF&&graphm[e_][i]!=INF)
            {
                if(mini>graphy[s_][i]+graphm[e_][i])
                    mini=graphy[s_][i]+graphm[e_][i];
            }
        }
        for(int i=0;i<26;i++)
        {
            if(graphy[s_][i]!=INF&&graphm[e_][i]!=INF)
            {
                if(mini==graphy[s_][i]+graphm[e_][i])
                {
                    ans.push_back(i+65);
                }
            }
        }
        if(mini==INF)
        {
            cout<<"You will never meet.\n";
        }
        else
        {
            sort(ans.begin(),ans.end());
            cout<<mini;
            for(int i=0;i<ans.size();i++)
                cout<<" "<<ans[i];
            cout<<"\n";
        }
    }
    return 0;
}

