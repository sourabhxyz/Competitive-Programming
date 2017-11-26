#include<bits/stdc++.h>

using namespace std;

struct ans
{
    char c;
    int cnt;
    ans() {}
    ans(char c_, int cnt_)
    {
        c = c_;
        cnt = cnt_;
    }
    bool operator < (const ans &other) const
    {
        if(cnt != other.cnt) return cnt < other.cnt;
        else return c > other.c;
    }
};

vector<ans> final;
string line[55];
int x, y;
map<char, int> data;
int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};

int floodfill(int r, int c, char c1, char c2)
{
    if(r < 0 || r >= x || c < 0 || c >= y) return 0;
    if(line[r][c] != c1) return 0;
    line[r][c] = c2;
    int ans = 1;
    int nr, nc;
    for(int i = 0; i < 4; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        ans += floodfill(nr, nc, c1, c2);
    }
    return ans;
}

int main()
{
    freopen("ina.txt", "r", stdin);
    freopen("outa.txt", "w", stdout);
    int t = 0;
    while(cin >> x >> y && (x || y))
    {
        final.clear();
        t++;
        data.clear();
        for(int i = 0; i < x; i++)
        {
            cin >> line[i];
        }
        cout << "Problem " << t << ":\n";
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(line[i][j] != '.' && line[i][j] != '@')
                {
                    char temp = line[i][j];
                    final.push_back(ans(temp, floodfill(i, j, line[i][j], '@')));
                    //int new_ = floodfill(i, j, line[i][j], '@');
                    //data[temp] = max(data[temp], new_);
                }
            }
        }
        /*map<char, int>::iterator it;
        for(it = data.begin(); it != data.end(); it++)
        {
            ans temp;
            temp.c = it -> first;
            temp.cnt = it -> second;
            final.push_back(temp);
        }*/
        sort(final.begin(), final.end());
        for(int i = final.size() - 1; i >= 0; i--)
        {
            cout << final[i].c << " " << final[i].cnt << "\n";
        }
        //cout << data['A'] << " " << data['C'] << "\n";

    }
}
