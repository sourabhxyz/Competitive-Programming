const int m1 = (int) 1e9 + 7;
inline int add(int a, int b) {
    a += b;
    if (a >= m1) a -= m1;
    return a;
}

inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += m1;
    return a;
}

inline int mul(int a, int b) {
    return (int) ((long long) a * b % m1);
}

inline int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a) {
    return power(a, m1 - 2);
}