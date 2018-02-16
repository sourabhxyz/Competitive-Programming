#include<bits/stdc++.h>

using namespace std;

string line[1000];
vector<pair<int, int> > pos;
int R;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c)
{
    if(line[r][c] == '*' || line[r][c] == ' ')
    {
        line[r][c] = '#';
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < R && nc >=0 && nc < line[nr].size())
            {
                floodfill(nr, nc);
            }
        }
    }
}

int main()
{
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int N;
    cin >> N;
    cin.ignore();
    string tline;
    string lineb;
    while(N--)
    {
        int k = 0;
        while(getline(cin, tline))
        {
            for(int i = 0; i < tline.size(); i++)
            {
                if(tline[i] == '*')
                {
                    pos.push_back(make_pair(k, i));
                }
            }
            if(tline[0] == '_')
            {
                lineb = tline;
                break;
            }
            line[k++] = tline;
        }
        R = k;
        for(int i = 0; i < pos.size(); i++)
        {
            int r = pos[i].first, c = pos[i].second;
            floodfill(r, c);
        }
        for(int i = 0; i < R; i++) {
            cout << line[i] << "\n";
        }
        cout << lineb << "\n";
    }
    return 0;
}
