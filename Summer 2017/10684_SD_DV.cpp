
#include<bits/stdc++.h>

#define FileIn(file) freopen(file".txt", "r", stdin)
#define FileOut(file) freopen(file".txt", "w", stdout)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    //FileIn("in");
    //FileOut("out");
    int n;
    while(cin>>n&&n)
    {
        int arr[n];
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            ans=max(ans,sum);
            if(sum < 0) sum = 0;
        }
        if(sum > 0)
            cout<<"The maximum winning streak is "<<ans<<".\n";
        else
            cout<<"Losing streak.\n";
    }
}


