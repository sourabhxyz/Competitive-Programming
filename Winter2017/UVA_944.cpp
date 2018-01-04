#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int f(int x)
{
    int sq = 0, temp;
    while(x > 0)
    {
        temp = x % 10;
        sq += temp * temp;
        x /= 10;
    }
    return sq;
}

int determine(int num) {
    int iter = 1;
    while(num != 1) {
        num = f(num);
        iter++;
    }
    return (iter);
}
ii floydCycleFinding(int x0) { // function int f(int x) is defined earlier
// 1st part: finding k*mu, hare’s speed is 2x tortoise’s
    int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
// 2nd part: finding mu, hare and tortoise move at the same speed
    int mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
// 3rd part: finding lambda, hare moves, tortoise stays
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) { hare = f(hare); lambda++; }
    return ii(mu, lambda);
}

map<int, int> data;

void pre() {
    for(int i = 1; i <= 99999; i++) {
        ii check = floydCycleFinding(i);
        if(check.second == 1) {
            int iter = determine(i);
            data[i] = iter;
        }
    }
//    for(map<int, int>::iterator it = data.begin(); it != data.end(); it++) {
//        cout << it -> first << " " << it -> second << " \n";
//    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    pre();
    int l, h;
    bool first = true;
    while(cin >> l >> h) {
        if(first) first = false;
        else cout << "\n";
        for(int i = l; i <= h; i++) {
            if(data.find(i) == data.end()) continue;
            cout << i << " " << data[i] << "\n";
        }
    }
}
