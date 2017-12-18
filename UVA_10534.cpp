#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define inf 10000

int n;
vector<int> seq;

pair<int, vector<int> > LIS(vector<int> &Sequence) { // which runs the NlogK LIS algorithm
    vector<int> L(n);
    int i; // auxilary variable for iteration
    vector<int> I(n + 1);
    I[0] = -inf; // I[0] = -infinite
    for( i = 1; i <= n; i++ ) // observe that i <= n are given
        I[i] = inf; // I[1 to n] = infinite
    int LisLength = 0; // keeps the maximum position where a data is inserted
    for( i = 0; i < n; i++ ) { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position
        while( low <= high ) { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        L[i] = low;
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }
    return make_pair(LisLength, L); // return the result
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(0);
    while(cin >> n) {
        seq.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> seq[i];
        }
        pair<int, vector<int> > f = LIS(seq);
        vector<int> oriseq = seq;
        reverse(seq.begin(), seq.end());
        pair<int, vector<int> > s = LIS(seq);
        vector<int> inc = f.second, dec = s.second;
        reverse(dec.begin(), dec.end());
        int mx = -1;
        for(int i = 0; i < n; i++) {
            int mm = min(inc[i], dec[i]);
            mm = 2 * mm - 1;
            if(mm > mx) {
                mx = mm;
            }

        }
        cout << mx << "\n";
    }
    return 0;
}
