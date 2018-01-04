#include<bits/stdc++.h>

using namespace std;

string line[10000];
map<string, int> data;
vector<vector<int> > glist;
int dist[100000];

void bfs(int from)
{
    //dist.assign(10000, 100000);
    for(int i = 0; i < 10000; i++) dist[i] = 100000;
    dist[from] = 0;
    queue<int> q;
    q.push(from);
    while(!q.empty())
    {
        int at = q.front(); q.pop();
        for(int i = 0; i < glist[at].size(); i++)
        {
            int to = glist[at][i];
            if(dist[to] == 100000)
            {
                dist[to] = dist[at] + 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        cout << "Scenario " << tc << "\n";
        data.clear();
        glist.clear();
        glist.resize(10000);
        int p, n;
        cin >> p >> n;
        cin.ignore();
        string temp;
        int vert = 0;
        for(int pa = 0; pa < p; pa++)
        {
            vector<string> names;
            getline(cin, temp);
            stringstream ss;
            ss << temp;
            string tname, tname2;
            while(ss >> tname) {
                ss >> tname2;
                tname += ' ';
                tname += tname2;
                tname.pop_back();
                names.push_back(tname);
                if(data.find(tname) == data.end())
                {
                    data[tname] = vert++;
                }
                if(tname2[tname2.size() - 1] == ':') break;
            }
            for(int i = 0; i < names.size(); i++)
            {
                for(int j = i + 1; j < names.size(); j++)
                {
                    glist[data[names[i]]].push_back(data[names[j]]);
                    glist[data[names[j]]].push_back(data[names[i]]);
                }
            }
        }
        bfs(data["Erdos, P."]);

        for(int i = 0; i < n; i++)
        {
            getline(cin, temp);
            cout << temp << " ";
            if(data.find(temp) == data.end())
            {
                cout << "infinity";
            }
            else if(dist[data[temp]] != 100000) cout << dist[data[temp]];
            else cout << "infinity";
            cout << "\n";
        }
    }
}
