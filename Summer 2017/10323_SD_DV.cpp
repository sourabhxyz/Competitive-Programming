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
    //cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    llu fact[15];
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<15;i++)
    {
        fact[i]=i*fact[i-1];
    }
    int n;
    while(cin>>n)
    {
        if(n<0)
        {
            if(n%2==0) cout<<"Underflow!\n";
            else cout<<"Overflow!\n";
            continue;
        }
        else if(n<=7) cout<<"Underflow!\n";
        else if(n>=14) cout<<"Overflow!\n";
        else
            cout<<fact[n]<<"\n";
    }
    return 0;
}

