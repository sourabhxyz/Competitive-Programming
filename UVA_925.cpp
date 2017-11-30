#include<bits/stdc++.h>

using namespace std;

map<string, int> mp;
int g[125][125];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        mp.clear();
        int k;
        cin >> k;
        map<string, set<string> > data;
        map<string, set<string> >:: iterator it;
        for(int i = 0; i < k; i++)
            for(int j = i; j < k; j++)
                g[i][j] = g[j][i] = 0;
        vector<string> bmp;
        for(int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            mp[s] = i;
            bmp.push_back(s);
        }
        int h;
        cin >> h;
        vector<vector<int > > nb;
        nb.resize(k);
        for(int i = 0; i < h; i++)
        {
            string temp;
            cin >> temp;
            int to = mp[temp];
            int f;
            cin >> f;
            for(int j = 0; j < f; j++)
            {
                cin >> temp;
                int from = mp[temp];
                g[from][to] = 1;
                nb[to].push_back(from);
            }
        }
        for(int l = 0; l < k; l++)
        {
            for(int i = 0; i < k; i++)
            {
                for(int j = 0; j < k; j++)
                {
                    g[i][j] |= g[i][l] & g[l][j];
                }
            }
        }

        for(int i = 0; i < k; i++)
        {
            if (nb[i].size() > 0)
            {
                vector<bool> nota(k, false);
                for(int m = 0; m < nb[i].size(); m++)
                {
                    for(int l = 0; l < nb[i].size(); l++)
                    {
                        if(g[nb[i][l]][nb[i][m]])
                        {
                            nota[l] = true;
                        }
                    }
                }
                for(int m = 0; m < nb[i].size(); m++)
                {
                    if(!nota[m])
                    {
                        data[bmp[i]].insert(bmp[nb[i][m]]);
                        //ans.push_back(nb[i][m]);
                    }
                }
            }
        }
        for(it = data.begin(); it != data.end(); it++)
        {
            set<string>::iterator nit;
            cout << it->first << " " << it->second.size();
            for(nit = (it->second).begin(); nit != (it->second.end()); nit++)
            {
                cout << " " << *nit;
            }
            cout << "\n";
        }
    }
}
