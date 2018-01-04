#include<bits/stdc++.h>

using namespace std;

#define INF 100000

double mat[205][205];

struct point{
    int x, y;
    point() {}
    point(int x_, int y_)
    {
        x = x_; y = y_;
    }
};

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

vector<point> data;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int n;
    for(int tc = 1; cin >> n && n; tc++)
    {
        data.clear();
        point fred;
        cin >> fred.x >> fred.y;
        point fiona;
        cin >> fiona.x >> fiona.y;
        data.push_back(fred);
        data.push_back(fiona);
        for(int i = 2; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            data.push_back(point(x, y));
        }
        for(int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                mat[i][j] = mat[j][i] = dist(data[i], data[j]);
            }
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    mat[i][j] = min(mat[i][j], max(mat[i][k], mat[k][j]));
                }
            }
        }
        cout << "Scenario #" << tc << "\n";
        cout << "Frog Distance = " << fixed << setprecision(3) << mat[0][1];
        cout << "\n\n";
    }
    return 0;
}
