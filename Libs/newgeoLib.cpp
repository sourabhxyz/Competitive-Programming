const double eps = 1e-8;
const double pi = 2 * acos(0);
struct vec {
    double x, y;
    vec () {}
    vec(double xx, double yy) {
        x = xx; y = yy;
    }
    vec operator + (const vec &other) const {
        return vec(x + other.x, y + other.y);
    }
    vec operator - (const vec &other) const {
        return vec(x - other.x, y - other.y);
    }
    vec operator / (const double &div) const {
        return vec(x / div, y / div);
    }
    vec operator * (const double &mul) const {
        return vec(x * mul, y * mul);
    }
    bool operator < (const vec &other) const{
        if(abs(x - other.x) > eps) return x < other.x;
        return y < other.y;
    }
    bool operator == (const vec &other) const{
        return (abs(x - other.x) < eps && abs(y - other.y) < eps);
    }
};

vec perp(vec a) {
    return vec(-a.y, a.x);
}
double abs(vec a) {
    return sqrt(a.x * a.x + a.y * a.y);
}
double dist(vec a, vec b) {
    return hypot(a.x - b.x, a.y - b.y);
}

struct line{
    double a, b, c;
};

void vecsToLine(vec p1, vec p2, line &l) {
    if (fabs(p1.x - p2.x) < eps) { // vertical line is fine
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < eps) && (fabs(l1.b-l2.b) < eps); }
bool areSame(line l1, line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < eps); }

bool areIntersect(line l1, line l2, vec &p) {
    if (areParallel(l1, l2)) return false; // no intersection
    /* Above condition needs to modified if the same lines also need to be considered */
// solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > eps) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}
struct linesegment{
    vec a, b;
    line l;
    linesegment() {}
    linesegment(vec aa, vec bb) {
        vecsToLine(aa, bb, l);
        a = aa; b = bb;
    }
};
bool lieson(linesegment l, vec p) {
    return (p.x > min(l.a.x, l.b.x) - eps and p.x < max(l.a.x, l.b.x) + eps and p.y > min(l.a.y, l.b.y) - eps and p.y < max(l.a.y, l.b.y) + eps);
}
bool intersectLineSegWithLine(linesegment l1, line l2) {
    vec p;
    return (areIntersect(l1.l, l2, p) and lieson(l1, p));
}
line abcToLine(double a, double b, double c) {
    if (abs(b) < eps) {
        double temp = a;
        a = 1;
        c /= temp;
    } else {
        double temp = b;
        b = 1;
        a /= temp;
        c /= temp;
    }
    line l;
    l.a = a; l.b = b; l.c = c;
    return l;
}

double dot(vec a, vec b)
{ return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v)
{ return v.x * v.x + v.y * v.y; }
double angle(vec a, vec o, vec b)
{ // returns angle aob in rad
    vec oa = a - o, ob = b - o;
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(vec p, vec q, vec r) {
    return cross(q - p, r - q) > 0; }

vec rotate(vec p, double theta) {
    double rad = theta * pi / 180;
    return vec(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad));
}
vec rotatewrto(vec p, vec o, double theta) {
    double rad = theta * pi / 180;
    return vec(o.x + (p.x - o.x) * cos(rad) - (p.y - o.y) * sin(rad),
               o.y + (p.x - o.x) * sin(rad) + (p.y - o.y) * cos(rad));
}

bool collinear(vec p, vec q, vec r) {
    return (abs(cross(q - p, r - q)) < eps);
}
