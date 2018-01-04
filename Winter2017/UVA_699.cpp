#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int, int> ii;
int ch;
vector<int> leftpiles, rightpiles;
int zero, mxleftcnt, mxrightcnt;

void go(int at, int leftcnt)
{
    if(leftcnt == 0)
    {
        zero += at;
    }
    if(leftcnt < 0)
    {
        mxrightcnt = max(mxrightcnt, abs(leftcnt));
        rightpiles[abs(leftcnt) - 1] += at;
    }
    if(leftcnt > 0)
    {
        mxleftcnt = max(mxleftcnt, leftcnt);
        leftpiles[leftcnt - 1] += at;
    }
    cin >> ch;
    if(ch != -1)
    {
        go(ch, leftcnt + 1);
    }
    cin >> ch;
    if(ch != -1)
    {
        go(ch, leftcnt - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    int casno = 1;
    while(cin >> n && n != -1)
    {
        cout << "Case " << casno++ << ":\n";
        zero = 0; leftpiles.clear(); rightpiles.clear();
        leftpiles.resize(81); rightpiles.resize(81);
        mxleftcnt = mxrightcnt = 0;
        go(n, 0);
        bool z = false;
        if(mxleftcnt > 0)
        {
            cout << leftpiles[mxleftcnt - 1];
            for(int i = mxleftcnt - 2; i >= 0; i--)
            {
                cout << " " << leftpiles[i];
            }
            cout << " " << zero;
        }
        else {
            for(int i = mxleftcnt - 1; i >= 0; i--)
            {
                cout << leftpiles[i] << " ";
            }
            cout << zero;
        }
        for(int i = 0; i < mxrightcnt; i++)
        {
            cout << " " << rightpiles[i];
        }
        cout << "\n\n";
    }
    return 0;
}
