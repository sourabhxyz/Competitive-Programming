#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

string line[10];
int mat[10][10];
int dc[] = {0, 1, 0, -1};
int dr[] = {1, 0, -1, 0};
bool alloff;

bool bound(int nr, int nc) {
    if(nr < 0 || nc < 0 || nr >= 10 || nc >= 10) return false;
    return true;
}

void toggle(int r, int c) {
    mat[r][c] = 1 - mat[r][c];
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(bound(nr, nc)) {
            mat[nr][nc] = 1 - mat[nr][nc];
        }
    }
}

int cnt = 0;

void process() {
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(mat[i - 1][j]) {
                toggle(i, j);
                cnt++;
            }
        }
    }
    alloff = true;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(mat[i][j]) {
                alloff = false;
                i = 10; j = 10;
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    //cout << fixed << setprecision(2);
    string name;
    while(cin >> name and name != "end") {
        cout << name << " ";
        for(int i = 0; i < 10; i++) {
            cin >> line[i];
            for(int j = 0; j < 10; j++) {
                if(line[i][j] == 'O') {
                    mat[i][j] = 1;
                }
                else {
                    mat[i][j] = 0;
                }
            }
        }
        int backup[10][10];
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                backup[i][j] = mat[i][j];
            }
        }
        for(int i = 0; i < (1 << 10); i++) {
            cnt = 0;
            for(int l = 0; l < 10; l++) {
                for(int m = 0; m < 10; m++) {
                    mat[l][m] = backup[l][m];
                }
            }
            for(int b = 0; b < 10; b++) {
                if((i & (1 << b))) {
                    toggle(0, b);
                    cnt++;
                }
            }
            process();
            if(alloff) {
                cout << cnt << "\n";
                break;
            }
        }
    }
    return 0;
}
