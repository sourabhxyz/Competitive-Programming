/*I made it exceptionally complicated*/
#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-7
struct point{
    int x, y;
    point() {}
    point(int u, int v) {
        x = u; y = v;
    }
    bool operator == (const point &other) const{
        return (x == other.x && y == other.y);
    }
};

int math[100][100], matv[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(6);
    int n, m, tc = 1;
    bool first = true;
    while(cin >> n >> m) {
        if(first) first = false;
        else {
            cout << "\n**********************************\n\n";
        }
        for(int i = 0; i < 100; i++) for(int j = 0; j < 100; j++) math[i][j] = matv[i][j] = 0;
        vector<point> data;
        vector<point>::iterator it;
        char ch;
        for(int i = 0; i < m; i++) {
            cin >> ch;
            if(ch == 'H') {
                int u, v;
                cin >> u >> v;
                point a = point(u, v);
                point b = point(u, v + 1);
                int ths = u * n + v;
                int nxt = u * n + v + 1;
                math[ths][nxt] = math[nxt][ths] = 1;
                it = find(data.begin(), data.end(), a);
                if(it == data.end()) {
                    data.push_back(a);
                }
                it = find(data.begin(), data.end(), b);
                if(it == data.end()) {
                    data.push_back(b);
                }
            }
            else {
                int u, v;
                cin >> u >> v;
                point a = point(v, u);
                point b = point(v + 1, u);
                int ths = v * n + u;
                int nxt = (v + 1) * n + u;
                matv[ths][nxt] = matv[nxt][ths] = 1;
                it = find(data.begin(), data.end(), a);
                if(it == data.end()) {
                    data.push_back(a);
                }
                it = find(data.begin(), data.end(), b);
                if(it == data.end()) {
                    data.push_back(b);
                }
            }
        }
       
        int len = data.size();
        for(int k = 0; k <= n * n + n; k++) {
            for(int i = 0; i <= n * n + n; i++) {
                for(int j = 0; j <= n * n + n; j++) {
                    math[i][j] |= math[i][k] & math[k][j];
                    matv[i][j] |= matv[i][k] & matv[k][j];
                }
            }
        }
        int arr[11];
        memset(arr, 0, sizeof arr);
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                for(int c1 = 1; c1 <= n; c1++) {
                    for(int c2 = c1 + 1; c2 <= n; c2++) {
                        if(j - i == c2 - c1 && matv[i * n + c1][j * n + c1] && math[j * n + c1][j * n + c2] && matv[j * n + c2][i * n + c2] && math[i * n + c1][i * n + c2])
                        {
                            arr[j - i]++;
                        }
                    }
                }
            }
        }
        
        cout << "Problem #" << tc++ << "\n\n";
        bool exist = false;
        for(int i = 0; i < 11; i++) {
            if(arr[i] > 0) {
                cout << arr[i] << " square (s) of size " << i << "\n";
                exist = true;
            }
        }
        if(!exist) {
            cout << "No completed squares can be found.\n";
        }

    }
    return 0;
}
