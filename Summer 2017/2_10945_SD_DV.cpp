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
    int cnt,sizes;
    string line;
    while(getline(cin,line)&&line!="DONE")
    {
        sizes=line.size();
        for(int i=0;i<sizes;i++)
        {
            line[i]=tolower(line[i]);
            if(line[i]<97)
            {
                line.erase(line.begin()+i);
                i--;
                sizes--;
            }
        }
        cnt=0;
        for(int i=0;i<=line.size()/2;i++)//to check for palindrome
        {
            if(line[i]==line[line.size()-i-1])
                cnt++;
        }
        if(cnt==line.size()/2+1)
        {
            cout<<"You won't be eaten!"<<endl;
        }
        else
            cout<<"Uh oh.."<<endl;
    }

    return 0;
}

