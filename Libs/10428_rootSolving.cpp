#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
struct Polynomial {
    vector<double> coef;
    int deg;
    Polynomial() {}
    Polynomial(int dd) {
        deg = dd;
        coef.resize(deg + 1);
    }
    void fix(Polynomial &given) {
        int dec = 0;
        for (int i = given.deg; i >= 0; i--) {
            if (abs(given.coef[i]) < eps) {
                dec++;
            } else break;
        }
        dec *= -1;
        given.coef.resize(given.deg + dec + 1);
        given.deg += dec;
        return;
    }
    Polynomial operator + (const Polynomial &other) {
        Polynomial ret;
        if (deg > other.deg) {
            ret.deg = deg;
            ret.coef.resize(deg + 1);
            for (int i = deg; i > other.deg; i--) {
                ret.coef[i] = coef[i];
            }
            for (int i = other.deg; i >= 0; i--) {
                ret.coef[i] = coef[i] + other.coef[i];
            }
            fix(ret);
            return ret;
        } else {
            ret.deg = other.deg;
            ret.coef.resize(other.deg + 1);
            for (int i = other.deg; i > deg; i--) {
                ret.coef[i] = other.coef[i];
            }
            for (int i = deg; i >= 0; i--) {
                ret.coef[i] = coef[i] + other.coef[i];
            }
            fix(ret);
            return ret;
        }
    }
    Polynomial operator - (const Polynomial &other) {
        Polynomial ret;
        if (deg > other.deg) {
            ret.deg = deg;
            ret.coef.resize(deg + 1);
            for (int i = deg; i > other.deg; i--) {
                ret.coef[i] = coef[i];
            }
            for (int i = other.deg; i >= 0; i--) {
                ret.coef[i] = coef[i] - other.coef[i];
            }
            fix(ret);
            return ret;
        } else {
            ret.deg = other.deg;
            ret.coef.resize(other.deg + 1);
            for (int i = other.deg; i > deg; i--) {
                ret.coef[i] = other.coef[i];
            }
            for (int i = deg; i >= 0; i--) {
                ret.coef[i] = coef[i] - other.coef[i];
            }
            fix(ret);
            return ret;
        }
    }
    Polynomial operator * (const pair<double, int> u) {
        double d = u.first;
        int dega = u.second;
        Polynomial ret;
        ret.deg = deg + dega;
        ret.coef.assign(ret.deg + 1, 0);
        for (int i = deg; i >= 0; i--) {
            ret.coef[i + dega] = (coef[i] * d);
        }
        fix(ret);
        return ret;
    }
    bool operator != (const Polynomial &other) {
        if (deg != other.deg) return true;
        for (int i = deg; i >= 0; i--) {
            if (coef[i] != other.coef[i]) return true;
        }
        return false;
    }

};

pair<Polynomial, Polynomial> polyDiv(Polynomial &n, Polynomial &d) { // To do n / d
    Polynomial zero;
    zero.deg = 0;
    zero.coef.push_back(0);
    if (n.deg < d.deg) {
        return make_pair(zero, n);
    }
    Polynomial q;
    q.deg = (n.deg);
    q.coef.assign(q.deg + 1, 0);
    Polynomial r = n;
    while (r != zero and r.deg >= d.deg) {
        double t = (r.coef[r.deg] / d.coef[d.deg]);
        q.coef[r.deg - d.deg] += t;
        r = r - d * make_pair(t, r.deg - d.deg);
    }
    q.fix(q); r.fix(r);
    return make_pair(q, r);
}
double f(Polynomial &a, double x) {
    double result = 0;
    for (int i = a.deg; i >= 0; i--) {
        result = result * x + a.coef[i];
    }
    return result;
}
double f_(Polynomial &a, double x) {
    double result = 0;
    for (int i = a.deg; i > 0; i--) {
        result = result * x + a.coef[i] * i;
    }
    return result;
}
double newtonsMethod(Polynomial &a, double x0) {
    double x1 = x0;
    while (true) {
        x0 = x1;
        x1 = x0 - f(a, x0)/f_(a, x0);
        if (abs(x1 - x0) < eps) break;
    }
    return x1;
}
void findRoot(Polynomial a, vector<double> &roots, int n) {
    for (int i = 0; i < n; i++) {
        roots.push_back(newtonsMethod(a, 0));
        Polynomial d(1);
        d.coef[1] = 1;
        d.coef[0] = -roots.back();
        auto u = polyDiv(a, d);
        a = u.first;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   //  freopen("ina.txt", "r", stdin);
   //  freopen("outa.txt", "w", stdout);
    cout << fixed << setprecision(4);
    int n;
    int caseno = 0;
    while (cin >> n and n) {
        Polynomial a(n);
        caseno++;
        for (int i = n; i >= 0; i--) {
            cin >> a.coef[i];
        }
        cout << "Equation " << caseno << ": ";
        vector<double> roots;
        findRoot(a, roots, n);
        sort(roots.begin(), roots.end());
        cout << roots[0];
        for (int i = 1; i < n; i++) {
            cout << " " << roots[i];
        }
        cout << "\n";
    }
}