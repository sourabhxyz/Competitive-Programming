#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string, int> msi;
typedef map<int,pair<int,int>> miii;
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
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
	int n;
	int p;
	int arr[1002];
	int minimum,num,cnt;
	string temp;
	bool first;
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
    {
        scanf("%d",&p);
        minimum=999;
        cin.ignore();
        for(int i=1;i<=p;i++)
        {
            cnt=0;
            stringstream strm;
            string line;
            getline(cin,line);
            strm<<line;
            while(strm>>num)
            {
                cnt++;
                arr[i]=cnt;
            }
            if(arr[i]<=minimum)
            {
                minimum=arr[i];
            }
        }
        first=true;
        for(int i=1;i<=p;i++)
        {
            if(arr[i]==minimum)
            {
                if(first)
                {
                    first=false;
                    printf("%d",i);
                }
                else
                printf(" %d",i);
            }
        }
        printf("\n");
        if(n!=0)
        getline(cin,temp);
    }
    return 0;
}
