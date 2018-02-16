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
#define EPS 1e-8

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    string line[100];
    int cnt = 0;
    while(getline(cin,line[0]))
    {
        cnt++;  
        bool decodable = true;
        int i = 1;
        while(getline(cin,line[i])&&line[i]!="9") i++;
        for(int k = 0;k<i;k++)
        {
            for(int j = 0;j<i;j++)
            {
                if(j==k) continue;
                string temp = line[j];
                while(temp!=line[k]&&temp.size()>0)
                {
                    temp.pop_back();
                }
                if(temp.size()==0) continue;
                else{
                    decodable = false;
                    k = j = i;
                }
            }
        }
        if(decodable) cout<<"Set "<<cnt<<" is immediately decodable\n";
        else cout<<"Set "<<cnt<<" is not immediately decodable\n";
    }
    return 0;
}

