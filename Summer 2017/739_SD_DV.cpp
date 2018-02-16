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

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    string line;
    map<char,int> data;
    data['B'] = 1;
    data['P'] = 1;
    data['F'] = 1;
    data['V'] = 1;
    data['C'] = 2;
    data['S'] = 2;
    data['K'] = 2;
    data['G'] = 2;
    data['J'] = 2;
    data['Q'] = 2;
    data['X'] = 2;
    data['Z'] = 2;
    data['D'] = 3;
    data['T'] = 3;
    data['L'] = 4;
    data['M'] = 5;
    data['N'] = 5;
    data['R'] = 6;
    cout<<"         NAME                     SOUNDEX CODE\n";
    while(cin>>line)
    {
        cout<<"         "<<line;
        for(int i = 0;i<25-line.size();i++) cout<<" ";
        char ch = line[0];
        int cnt = 0;
        cout<<ch;
        for(int i =1;i<line.size()&&cnt<3;i++)
        {
            if(data[ch] == data[line[i]]) continue;
            else
            {
                ch = line[i];
                if(data[ch]!=0)
                {
                    cout<<data[ch];
                    cnt++;
                }
            }
        }
        for(int i = cnt;i<3;i++)
            cout<<"0";
        cout<<"\n";
    }
    cout<<"                   END OF OUTPUT\n";
    return 0;
}

