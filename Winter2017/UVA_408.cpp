#include<bits/stdc++.h>

using namespace std;

int step, mod;

int f(int x0) {
    return (x0 + step) % mod;
}

int floydCycleFinding(int x0) { // function int f(int x) is defined earlier
// 1st part: finding k*mu, hare’s speed is 2x tortoise’s
    int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
// 2nd part: finding mu, hare and tortoise move at the same speed
    int mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
// 3rd part: finding lambda, hare moves, tortoise stays
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) { hare = f(hare); lambda++; }
    return (lambda);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    while (cin >> step >> mod) {
        cout << setw(10) << step << setw(10) << mod;
        int lambda = floydCycleFinding(0);
        if (lambda == mod) cout << setw(5) << "    Good Choice\n";
        else cout << setw(5) << "    Bad Choice\n";
        cout << "\n";
    }
}
