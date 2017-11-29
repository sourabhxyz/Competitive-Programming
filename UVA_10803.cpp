#include<bits/stdc++.h>

using namespace std;

#define INF 100000

double mat[200][200];

struct point{
    int x, y;
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
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        data.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j) mat[i][j] = INF;
                else mat[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            data.push_back(point(x, y));
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                double dist_ = dist(data[i], data[j]);
                if(dist_ < 10 + 1e-6)
                    mat[i][j] = mat[j][i] = dist_;

            }
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        double ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                ans = max(ans, mat[i][j]);
            }
        }
        cout << "Case #" << tc << ":\n"; ans != INF ? cout << fixed << setprecision(4) << ans : cout << "Send Kurdy";
        cout << "\n\n";

    }
    return 0;
}
