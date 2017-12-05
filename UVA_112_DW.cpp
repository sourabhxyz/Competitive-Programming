#include<bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int, int> ii;
string final;
long long int reqno;
long long int globalindex;
vector<int> finalarr;
vector<bool> valid;
bool done;

int go(int from, long long int currsum)
{
    int left = finalarr[globalindex];
    bool cantakel = valid[globalindex];
    globalindex++;
    if(cantakel)
    {
        go(left, currsum + left);
    }
    int right = finalarr[globalindex];
    bool cantaker = valid[globalindex];
    globalindex++;
    if(cantaker)
    {
        go(right, currsum + right);
    }
    if(!cantakel && !cantaker)
    {
        if(reqno == currsum)
        {
            done = true;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    while(cin >> reqno)
    {
        done = false;
        final.clear();
        char c;
        cin >> c;
        int left = 1;
        while(c == ' ')
        {
            cin >> c;
        }
        final.push_back(c);
        int right = 0;
        while(right != left) {
            cin >> c;
            if (c == '(') {
                left++;
            }
            if (c == ')') right++;
            if (c != ' ' && c != '\n') {
                final.push_back(c);
            }
        }
        //cout << final << '\n';
        finalarr.clear();
        valid.clear();
        for(int i = 0; i < final.size(); i++)
        {
            c = final[i];
            if(i < final.size() - 1 && c == '(' && final[i + 1] == ')')
            {
                i++;
                finalarr.push_back(-1);
                valid.push_back(false);
                continue;
            }
            if(c == '(' || c == ')')
            {
                continue;
            }
            string num;
            if(isdigit(c) || c == '-')
            {
                num.push_back(c);
                i++;
                while(isdigit(final[i]))
                {
                    num.push_back(final[i]);
                    i++;
                }
                i--;
                int number = stoi(num);
                finalarr.push_back(number);
                valid.push_back(true);
            }
        }
        /*for(int i = 0; i < finalarr.size(); i++)
        {
            cout << finalarr[i] << " ";
        }*/
        if(finalarr[0] == -1)
        {
            cout << "no\n";
            continue;
        }
        globalindex = 1;
        go(finalarr[0], finalarr[0]);
        if(done)
        {
            cout << "yes\n";
        }
        else cout << "no\n";
    }
    return 0;
}
