#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

char input[407][407];
string s; 
int n, m, x, y;
int ans = 0;
bool dead = false;

inline bool is_dead() {
    return x < 1 || x > n || y < 1 || y > m;
}

void move(char op) {
    if(op == 'W') x--;
    if(op == 'A') y--;
    if(op == 'S') x++;
    if(op == 'D') y++;
    if(input[x][y] == 'o'){
        input[x][y] = '.'; 
        ans++;
    }
    dead = is_dead();
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i {1}; i <= n; ++i)
        for(int j {1}; j <= m; ++j)
            cin >> input[i][j];
    cin >> s;

    for(int i {1}; i <= n; ++i)
        for(int j {1}; j <= m; ++j)
            if(input[i][j] == '@') x = i, y = j;

    for(char op: s) {
        move(op);
        if(dead) {
            cout << "GG";
            return 0;
        }
    }
    cout << ans;

    // system("pause");
    return 0;
}