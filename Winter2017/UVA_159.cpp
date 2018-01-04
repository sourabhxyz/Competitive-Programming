#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("ina.txt", "r", stdin);
    //freopen("outa.txt", "w", stdout);
    string hor1;
    bool first = true;
    while(cin >> hor1 and hor1 != "#") {
        if(first) first = false;
        else cout << "\n";
        string ver1, hor2, ver2;
        cin >> ver1 >> hor2 >> ver2;
        bool check1 = false, check2 = false;
        int mark1, mark1v, mark2, mark2v;
        for(int i = 0; i < hor1.size(); i++) {
            for(int j = 0; j < ver1.size(); j++) {
                if(hor1[i] == ver1[j]) {
                    mark1 = i;
                    mark1v = j;
                    check1 = true;
                    i = hor1.size(); j = ver1.size();
                }
            }
        }
        if(!check1) {
            cout << "Unable to make two crosses\n";
            continue;
        }
        for(int i = 0; i < hor2.size(); i++) {
            for(int j = 0; j < ver2.size(); j++) {
                if(hor2[i] == ver2[j]) {
                    mark2 = i;
                    mark2v = j;
                    check2 = true;
                    i = hor2.size(); j = ver2.size();
                }
            }
        }
        if(!check2) {
            cout << "Unable to make two crosses\n";
            continue;
        }
        int maxh, maxv;
        maxh = hor1.size() + hor2.size() + 3;
        int start2h = hor1.size() + 3;
        vector<string> display;
        if(mark2v <= mark1v) {
            maxv = max(ver1.size(), mark1v - mark2v + ver2.size());
            display.resize(maxh);
            for(int i = 0; i < maxv; i++) {
                if(i < ver1.size()) {
                    if(i != mark1v) {
                        for (int j = 0; j < mark1; j++) {
                            display[i].push_back(' ');
                        }
                        display[i].push_back(ver1[i]);
                    }
                    else {
                        display[i].insert(display[i].end(), hor1.begin(), hor1.end());
                        for(int k = 0; k < 3; k++) display[i].push_back(' ');
                        display[i].insert(display[i].end(), hor2.begin(), hor2.end());
                    }
                    if(i >= mark1v - mark2v and i != mark1v and i < mark1v - mark2v + ver2.size()) {
                        for(int j = mark1 + 1; j < start2h + mark2; j++) {
                            display[i].push_back(' ');
                        }
                        display[i].push_back(ver2[i - (mark1v - mark2v)]);
                    }
                }
                else if(i < mark1v - mark2v + ver2.size()){
                    for(int j = 0; j < start2h + mark2; j++) {
                        display[i].push_back(' ');
                    }
                    display[i].push_back(ver2[i - (mark1v - mark2v)]);
                }
            }
        }
        else {
            maxv = max(mark2v - mark1v + ver1.size(), ver2.size());
            display.resize(maxh);
            for(int i = 0; i < maxv; i++) {
                if (i < ver2.size()) {
                    if (i < mark2v - mark1v) {
                        for (int j = 0; j < start2h + mark2; j++) {
                            display[i].push_back(' ');
                        }
                        display[i].push_back(ver2[i]);
                    } else if (i != mark2v and i < mark2v - mark1v + ver1.size()) {
                        for (int j = 0; j < mark1; j++) {
                            display[i].push_back(' ');
                        }
                        display[i].push_back(ver1[i - (mark2v - mark1v)]);
                        for (int j = mark1 + 1; j < start2h + mark2; j++) {
                            display[i].push_back(' ');
                        }
                        display[i].push_back(ver2[i]);
                    } else if (i == mark2v) {
                        display[i].insert(display[i].end(), hor1.begin(), hor1.end());
                        for (int k = 0; k < 3; k++) display[i].push_back(' ');
                        display[i].insert(display[i].end(), hor2.begin(), hor2.end());
                    } else {
                        for (int j = 0; j < start2h + mark2; j++) {
                            display[i].push_back(' ');
                        }
                        display[i].push_back(ver2[i]);
                    }
                } else {
                    for (int j = 0; j < mark1; j++) {
                        display[i].push_back(' ');
                    }
                    display[i].push_back(ver1[i - (mark2v - mark1v)]);
                }
            }
        }
        for(int i = 0; i < maxv; i++) {
            cout << display[i];
            cout << "\n";
        }

    }
    return 0;
}
