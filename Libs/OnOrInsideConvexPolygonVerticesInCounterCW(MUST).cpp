struct frac {
    int x, y; // frac is y / x

    void reduce() {
        if (y == 0) { // 0 slope
            x = 1;
        } else if (x == 0) { // inf slope
            y = inf;
        } else {
            if (x < 0) {
                x *= -1;
                y *= -1;
            }
            int d = gcd(abs(x), abs(y));
            x /= d;
            y /= d;
        }
    }
    bool operator == (const frac &other) const {
        return x == other.x and y == other.y;
    }
    bool operator < (const frac &other) const {
        return 1LL * x * other.y > 1LL * other.x * y;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("inc.txt", "r", stdin);
    freopen("outc.txt", "w", stdout);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<vec> p (n);
    int zero_id = 0;
    for (int i=0; i<n; ++i) {
        cin >> p[i].x >> p[i].y;
        // Getting the point with lowest x coordinate and in case of tie, the one with lower y ordinate
        if (p[i].x < p[zero_id].x || p[i].x == p[zero_id].x && p[i].y < p[zero_id].y)
            zero_id = i;
    }
    vec zero = p[zero_id];
    rotate (p.begin(), p.begin()+zero_id, p.end());
    p.erase (p.begin());
    --n;
    vector<frac> a (n);
    /* The way we have chosen zero_id, slope -inf is not possible. And since points are in CCW direction, 
    slope will form and increasing sequence in vector a
    */
    for (int i=0; i<n; ++i) {
        a[i].y = p[i].y - zero.y;
        a[i].x = p[i].x - zero.x;
        a[i].reduce();
    }
    for (;;) {
        vec q; // another query
        bool in = false;
        if (q.x >= zero.x)
            if (q.x == zero.x && q.y == zero.y)
                in = true;
            else {
                frac my;
                my.y = q.y-zero.y;
                my.x = q.x-zero.x;
                my.reduce();
                vector<frac>::iterator it = upper_bound (a.begin(), a.end(), my);
                if (it == a.end() && my.x == a[n-1].x && my.y == a[n-1].y)
                    it = a.end()-1;
                if (it != a.end() && it != a.begin()) {
                    int p1 = int (it - a.begin());
                    if (sq (p[p1], p[p1-1], q) <= 0) // just check here whether the point lies on 
                        // triangle (zero, p[p1 - 1], p[p1]) or not, so replace this with your 
                        // function. 
                        in = true;
                }
            }
        puts (in ? "INSIDE" : "OUTSIDE");
    }


}