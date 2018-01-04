#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, int> di;
#define inf 100000000
const double PI = 2 * acos(0);

#define MAX_N 102 // Fibonacci matrix, increase/decrease this value as needed
struct Matrix { ll mat[MAX_N][MAX_N]; }; // we will return a 2D array
Matrix matMul(Matrix a, Matrix b, int n) { // O(n^3)
    Matrix ans; int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (ans.mat[i][j] = k = 0; k < n; k++) // if necessary, use
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % 1000000; // modulo arithmetic
    return ans; }
Matrix matPow(Matrix base, int p, int n) { // O(n^3 log p)
    Matrix ans; int i, j;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)
            ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p) { // iterative version of Divide & Conquer exponentiation
        if (p & 1) ans = matMul(ans, base, n); // if p is odd (last bit is on)
        base = matMul(base, base, n); // square the base
        p >>= 1; // divide p by 2
    }
    return ans; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(2);
    int n, l;
    while(cin >> n >> l and (n + l)) {
        Matrix graph;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) graph.mat[i][j] = 0;
        for(int i = 0; i < l; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph.mat[u][v] = 1;
            graph.mat[v][u] = 1;
        }
        int s, e, d;
        cin >> s >> e >> d;
        Matrix ans = matPow(graph, d, n);
        (ans.mat[s - 1][e - 1]) ? cout << "Yes, Teobaldo can travel.\n" : cout << "No, Teobaldo can not travel.\n";
    }
    return 0;

}
