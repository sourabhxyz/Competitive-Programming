// This problem can well be handled with SAM as well, will code it once I get time.

/* General KMP. Assumption: To search p in t. 
vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

void kmp() {
    auto pref = prefix_function(p);
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        while (j > 0 and t[i] != p[j]) {
            j = pref[j - 1];
        }
        if (t[i] == p[j]) j++;
        if (j == p.size()) {
            cnt++;
            j = pref[j - 1];
        }
    }
} */

const int N = (int)2e5 + 1;

struct Part {
    char c;
    long long l;
    bool operator==(const Part &b) const {
        return (c == b.c) && (l == b.l);
    }
    bool operator<=(const Part &b) const {
        return (c == b.c) && (l <= b.l);
    }
};

int n, m, pi[N];
Part a[N], b[N];
long long ans;

void compress(Part *a, int &n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m == 0 || a[m - 1].c != a[i].c)
            a[m++] = a[i];
        else
            a[m - 1].l += a[i].l;
    }
    n = m;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%I64d-%c", &a[i].l, &a[i].c);

    for (int i = 0; i < m; i++)
        scanf("%I64d-%c", &b[i].l, &b[i].c);

    compress(a, n), compress(b, m), ans = 0;

    if (m == 1) {
        for (int i = 0; i < n; i++)
            if (b[0] <= a[i])
                ans += a[i].l - b[0].l + 1;
    } else if (m == 2) {
        for (int i = 0; i < n - 1; i++)
            if (b[0] <= a[i] && b[1] <= a[i + 1])
                ans++;
    } else {
        pi[1] = 0;
        for (int i = 2; i < m - 1; i++) {
            int j = pi[i - 1];
            while (j > 0 && !(b[j + 1] == b[i]))
                j = pi[j];
            if (b[j + 1] == b[i])
                j++;
            pi[i] = j;
        }
        for (int i = 1, j = 0; i < n - 1; i++) {
            while (j > 0 && !(b[j + 1] == a[i]))
                j = pi[j];
            if (b[j + 1] == a[i])
                j++;
            if (j == m - 2) {
                if (b[0] <= a[i - j] && b[j + 1] <= a[i + 1])
                    ans++;
                j = pi[j];
            }
        }
    }

    printf("%I64d", ans);

    return 0;
}