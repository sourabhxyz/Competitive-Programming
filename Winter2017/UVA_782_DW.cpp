#include<bits/stdc++.h>

using namespace std;

string line[33];
string tline;
string lineb;
int k;
int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};
bool used[33][83];

bool bound(int r, int c)
{
    if(r < 0 || r >= k || c < 0 || c >= line[r].size() || used[r][c]) return false;
    else return true;
}

void floodfill(int r, int c)
{
    if(!bound(r, c)) return;
    used[r][c] = true;
    for(int m = 0; m < 4; m++)
    {
        int nr = r + dr[m];
        int nc = c + dc[m];
        if(bound(nr, nc) && line[nr][nc] != ' ' && line[nr][nc] != '#')
        {
            line[r][c] = '#';
        }
        else if(bound(nr, nc) && (line[nr][nc] == ' ' || line[nr][nc] == '#'))
        {
            floodfill(nr, nc);
        }

    }
}

int main()
{
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        for(int i = 0; i < 33; i++) for(int j = 0; j < 82; j++) used[i][j] = false;
        for(int i = 0; i < 31; i++) {line[i].clear();}
        k = 0;
        while(getline(cin, tline))
        {
            if(tline == "") {
                for(int h = 0; h < 82; h++) line[k].push_back(' ');
                //line[k] = "                                                    ";
                k++;
            }
            else if(tline[0] == '_')
            {
                lineb = tline;
                break;
            }
            else {
                line[k++] = tline;
                for(int h = 0; h < 82 - line[k - 1].size(); h++)
                    line[k - 1].push_back(' ');
            }
            //cout << k << " " << line[k] << "\n";
            //k++;
        }
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < line[i].size(); j++)
            {
                if(line[i][j] == '*')
                {
                    line[i][j] = ' ';
                    floodfill(i, j);
                    break;
                }
            }
        }
        for(int i = 0; i < k; i++)
        {
            bool found = false;
            while(!found && line[i].size() > 0)
            {
                if(line[i][line[i].size() - 1] == ' ') line[i].pop_back();
                else found = true;
            }
        }
        for(int i = 0; i < k; i++)
        {
            cout << line[i] << "\n";
        }
        cout << lineb << "\n";
    }
    return 0;
}
