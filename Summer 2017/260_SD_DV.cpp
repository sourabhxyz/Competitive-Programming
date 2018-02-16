#include<bits/stdc++.h>

using namespace std;

string line[205];
string mod1[205];
string mod2[205];
int N;
int dr[] = {-1, -1, 0, 0, 1, 1};
int dc[] = {-1, 0, -1, 1, 0, 1};

void floodfill(int r, int c, char c1, char c2)
{
    if(r < 0 || r >= N || c < 0 || c >= N || mod1[r][c] != c1) return;
    mod1[r][c] = c2;
    for(int i = 0; i < 6; i++) {
        floodfill(r + dr[i], c + dc[i], c1, c2);
    }
}

int main()
{
    int t = 1;
    while(cin >> N && N != 0)
    {
        for(int i = 0; i < N; i++)
        {
            cin >> line[i];
            mod1[i] = line[i];
            mod2[i] = line[i];
        }
        cout << t++ << " ";
        bool black = false, white = false;
        /* For black */
        for(int i = 0; i < N; i++)
        {
            bool check1 = false, check2 = false;
            floodfill(0, i, 'b', '.');
            for(int j = 0; j < N; j++)
            {
                if(mod1[0][j] == '.') check1 = true;
                if(mod1[N - 1][j] == '.') check2 = true;
            }
            floodfill(0, i, '.', 'b');
            if(check1 && check2)
            {
                black = true;
                break;
            }
        }
        if(black)
        {
            cout << "B\n";
        }
        else
        {
            cout << "W\n";
        }
        /*for(int i = 0; i < N; i++)
        {
            bool check1 = false, check2 = false;
            floodfill(i, 0, 'w', '.');
            for(int j = 0; j < N; j++)
            {
                if(mod1[j][0] == '.') check1 = true;
                if(mod1[j][N - 1] == '.') check2 = true;
            }
            floodfill(i, 0, '.', 'w');
            if(check1 && check2)
            {
                white = true;
                break;
            }
        }*/

    }
    return 0;
}
