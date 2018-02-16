#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > AdjList;
map<char, int> data;
int k;
bool chosen[25];
vector<char> variables;
vector<char> ans;
bool found = false;

bool isValid(int u)
{
    for(int i = 0; i < AdjList[u].size(); i++)
    {
        int v = AdjList[u][i];
        if(chosen[v]) return false;
    }
    return true;
}

void bktk()
{
    if(ans.size() == k)
    {
        found = true;
        cout << ans[0];
        for(int i = 1; i < ans.size(); i++)
        {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    else
    {
        for(int i = 0; i < k; i++)
        {
            if(!chosen[i] && isValid(i))
            {
                //cout << variables[i] << " ";
                chosen[i] = true;
                ans.push_back(variables[i]);
                bktk();
                chosen[i] = false;
                ans.pop_back();
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        found = false;
        variables.clear();
        ans.clear();
        memset(chosen, 0, sizeof chosen);
        AdjList.clear();
        k = 0;
        data.clear();
        string line;
        getline(cin, line);
        getline(cin, line);
        for(int i = 0; i < line.size(); i += 2)
        {
            char c = line[i];
            data[c] = k++;
            variables.push_back(c);
        }
        //for(int i = 0; i < variables.size(); i++)
        //	cout << variables[i] << " ";
        //cout << k << '\n';
        AdjList.resize(k);
        getline(cin, line);
        for(int i = 0; i < line.size(); i += 4)
        {
            char c1 = line[i];
            char c2 = line[i + 2];
            AdjList[data[c1]].push_back(data[c2]);
            //cout << c1 << " " << c2;
        }
        bktk();
        if(!found) {
            cout << "NO\n";
        }
        if(t) cout << '\n';
    }
    return 0;
}
