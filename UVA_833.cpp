#include<bits/stdc++.h>

#define EPS 1e-9
#define INF 100000000

using namespace std;
struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS) // useful for sorting
            return x < other.x; // first criteria , by x-coordinate
        return y < other.y; }  // second criteria, by y-coordinate
// use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };
double dist(point p1, point p2) { // Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); } // return double
//------------------Line------------------------
struct linesegment{
    point end1, end2;
    linesegment() {}
    linesegment(point p1, point p2)
    {
        end1 = p1; end2 = p2;
    }
};

struct line {
    double a, b, c;
    line() {}
    line(double a_, double b_, double c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }
    line(point p1, point p2)
    {
        if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
            a = 1.0; b = 0.0; c = -p1.x; // default values
        } else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0; // IMPORTANT: we fix the value of b to 1.0
            c = -(double)(a * p1.x) - p1.y;
        }
    }
    bool operator == (const line &other) const{
        return ((fabs(a - other.a) < EPS) && (fabs(b - other.b) < EPS) && (fabs(c - other.c) < EPS));
    }
};

//-------------------END--------------------
vector<line> lines;
vector<linesegment> segs;
vector<pair<int, point> > sources;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        lines.clear();
        segs.clear();
        sources.clear();
        int np;
        cin >> np;
        for(int i = 0; i < np; i++)
        {
            vector<point> temp;
            int x, y;
            cin >> x >> y;
            temp.push_back(point(x, y));
            int x2, y2;
            cin >> x2 >> y2;
            temp.push_back(point(x2, y2));
            sort(temp.begin(), temp.end());
            segs.push_back(linesegment(temp[0], temp[1]));
            lines.push_back(line(temp[0], temp[1]));
        }
        int s;
        cin >> s;
        for(int i = 0; i < s; i++)
        {
            int x, y;
            cin >> x >> y;
            sources.push_back(make_pair(i, point(x, y)));
        }
        vector<pair<int, double> > ans;
        for(int i = 0; i < sources.size(); i++)
        {
            double x = sources[i].second.x, y = sources[i].second.y;
            vector<pair<double, int> > corr;
            for(int j = 0; j < lines.size(); j++)
            {
                line l = lines[j];
                double ly = -l.c - (l.a * x);
                if(y - ly < EPS) continue;
                if(-l.a > -EPS)
                {
                    if(ly < segs[j].end1.y || ly > segs[j].end2.y)
                        continue;
                } else
                {
                    if(ly > segs[j].end1.y || ly < segs[j].end2.y)
                        continue;
                }
                corr.push_back(make_pair(y - ly, j));
            }
            vector<pair<double, int> >:: iterator it;
            if(!corr.empty()) {
                it = min_element(corr.begin(), corr.end());
                line l = lines[it -> second];
                point np;
                if(-l.a > -EPS)
                {
                    np.x = segs[it -> second].end1.x;
                    np.y = segs[it -> second].end1.y;
                    sources.push_back(make_pair(sources[i].first, np));
                } else
                {
                    np.x = segs[it -> second].end2.x;
                    np.y = segs[it -> second].end2.y;
                    sources.push_back(make_pair(sources[i].first, np));
                }
            } else
            {
                ans.push_back(make_pair(sources[i].first, x));
            }

        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].second << "\n";
        }
        if(t > 0) cout << "\n";
    }
    return 0;
}
