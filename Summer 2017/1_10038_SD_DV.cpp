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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //FileIn("in");
    //FileOut("out");
    int n,cnt;
    while(cin>>n)
    {
        cnt=0;
        int a[n];
        const int t=n;
        bool yes[n]={false};
        yes[0]=true;
        cin>>a[0];
        if(n==1)
        {
            cout<<"Jolly"<<endl;
            continue;
        }
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            if(1<=abs(a[i]-a[i-1])&&abs(a[i]-a[i-1])<n)
            if(!yes[abs(a[i]-a[i-1])])
            {
                yes[abs(a[i]-a[i-1])]=true;
                cnt++;
            }
        }
        if(cnt==n-1)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }
    return 0;
}
