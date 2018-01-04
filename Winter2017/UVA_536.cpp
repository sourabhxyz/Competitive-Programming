#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int, int> ii;
struct node{
    int level;
    int name;
    string seq;
    node() {}
    node(int l, int n, string s)
    {
        level = l;
        name = n;
        seq = s;
    }
    bool operator < (const node &other) const{
        if(level != other.level) return level < other.level;
        return (seq <= other.seq);
    }
};

vector<node> data;
map<string, int> check;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string s;
    while(cin >> s)
    {
        bool old = false;
        check.clear();
        int mx = 0;
        data.clear();
        if(s == "()") continue;
        stringstream ss;
        ss << s;
        char junk;
        int name;
        ss >> junk >> name >> junk >> s;
        if(s == ")")
        {
            check[""] = 1;
            data.push_back(node(0, name, ""));
        } else
        {
            s.pop_back();
            if(check.find(s) != check.end())
            {
                old = true;
            }
            check[s] = 1;
            int s_ = s.size();
            data.push_back(node(s_, name, s));
            mx = max(mx, s_);
        }
        while(cin >> s && s != "()")
        {
            stringstream s2;
            s2 << s;
            s2 >> junk >> name >> junk >> s;
            if(s == ")")
            {
                check[""] = 1;
                data.push_back(node(0, name, ""));
            } else
            {
                s.pop_back();
                if(check.find(s) != check.end()) old = true;
                check[s] = 1;
                int s_ = s.size();
                data.push_back(node(s_, name, s));
                mx = max(mx, s_);
            }
        }
        sort(data.begin(), data.end());
        if(check.find("") == check.end() || old)
        {
            cout << "not complete\n";
            continue;
        }
        bool poss = true;
        for(int i = 1; i < data.size() && poss; i++)
        {
            string curr = data[i].seq;
            curr.pop_back();
            if(check.find(curr) == check.end())
            {
                poss = false;
            }
        }
        if(!poss)
        {
            cout << "not complete\n";
            continue;
        }
        cout << data[0].name;
        for(int i = 1; i < data.size(); i++)
        {
            cout << " " << data[i].name;
        }
        cout << "\n";
    }
    return 0;
}
