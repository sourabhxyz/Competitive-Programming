/*To check the constraints by going through all the permutations, and through all the 
constraints => complexity equals O(n*m*n!) 
although I should have used find keyword to simplify the things...*/
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
struct constr{
    int a;
    int b;
    int c;
    bool atmost;
};
int fact[9];
void compfact()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=8;i++)
    {
        fact[i]=i*fact[i-1];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n,m,temp,counter;
    bool first;
    compfact();
    vector< constr > data;
    while(cin>>n>>m&&(n||m))
    {
        if(m==0)
        {
            cout<<fact[n]<<"\n";
            continue;
        }
        counter=0;
        data.clear();
        data.resize(m+5);
        vi perm;
        for(int i=0;i<n;i++) perm.push_back(i);
        for(int i=0;i<m;i++)
        {
            cin>>data[i].a>>data[i].b>>temp;
            if(temp<0)
            {
                data[i].atmost=false;
                data[i].c=-1*temp;
            }
            else
            {
                data[i].c=temp;
                data[i].atmost=true;
            }
        }
        counter=0;
        do
        {
            temp=0;
            for (int i = 0; i < m; i++)
            {
                first=true;
                int j;
                for(int k=0;k<n;k++)
                {

                    if(perm[k]==data[i].a||perm[k]==data[i].b)
                    {
                        if(first){
                            first = false;
                            j=k;
                            continue;
                        }
                        else{
                            if(data[i].atmost)
                            {
                                if(abs(k-j)<=data[i].c)
                                {
                                    temp++;
                                    break;
                                }

                            }
                            else{
                                if(abs(k-j)>=data[i].c)
                                {
                                    temp++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(temp==m) counter++;
        }while (next_permutation(perm.begin(), perm.end()));

        cout<<counter<<"\n";
    }
    return 0;
}

