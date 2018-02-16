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
typedef map<int,pair<int,int>> miii;
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    string line;
    string temp;
    int pow,res;
    while(getline(cin,line))
    {
        res=0;
        pow=1;
        while(line[line.size()-1]!='#')
        {
            getline(cin,temp);
            line+=temp;
        }
        line.erase(line.begin()+line.size()-1);
        for(int i=line.size()-1;i>=0;i--)
        {
            if(line[i]=='1')
            {
                res+=pow;
            }
            pow=(pow*2)%131071;
        }
        if(res%131071==0)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}


