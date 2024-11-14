// 这份代码基于佟铭洋同学的想法，在了解思路后我自行写出的
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

void get_ans(int n, int m) {
    if(n == 3 and m == 3) cout << "000" << '\n' << "011" << '\n' << "101" << '\n';
    if(n == 3 and m == 4) cout << "0001" << '\n' << "0110" << '\n' << "1010" << '\n';
    if(n == 3 and m == 5) cout << "00011" << '\n' << "01100" << '\n' << "10101" << '\n';
    if(n == 3 and m == 6) cout << "000111" << '\n' << "011001" << '\n' << "101010" << '\n';
    if(n == 4 and m == 2) cout << "00" << '\n' << "01" << '\n' << "01" << '\n' << "01" << '\n';
    if(n == 4 and m == 3) cout << "000" << '\n' << "011" << '\n' << "101" << '\n' << "110" << '\n';
    if(n == 4 and m == 4) cout << "0001" << '\n' << "0110" << '\n' << "1010" << '\n' << "1100" << '\n';
    if(n == 4 and m == 5) cout << "00011" << '\n' << "01100" << '\n' << "10101" << '\n' << "11010" << '\n';
    if(n == 4 and m == 6) cout << "000111" << '\n' << "011001" << '\n' << "101010" << '\n' << "110100" << '\n';
    if(n == 5 and m == 3) cout << "001" << '\n' << "010" << '\n' << "011" << '\n' << "100" << '\n' << "101" << '\n';
    if(n == 5 and m == 4) cout << "0011" << '\n' << "0101" << '\n' << "0110" << '\n' << "1001" << '\n' << "1010" << '\n';
    if(n == 6 and m == 3) cout << "001" << '\n' << "010" << '\n' << "011" << '\n' << "100" << '\n' << "101" << '\n' << "110" << '\n';
    if(n == 6 and m == 4) cout << "0011" << '\n' << "0101" << '\n' << "0110" << '\n' << "1001" << '\n' << "1010" << '\n' << "1100" << '\n';
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    
    while(T--) {
        int n, m; cin >> n >> m;
        if(n == 2) {cout << string(m, '0') << "\n0" << string(m - 1, '1') << '\n'; continue;}
        if(m == 2) {
            cout << "00\n"; // << string(n - 1, "01\n"); 
            for(int i = 0; i < n - 1; i++) cout << "01\n";
            continue;}
        if(min(n, m) >= 5 or max(n, m) >= 7) {cout << "No solution\n"; continue; }
        get_ans(n, m);
    }

    // system("pause");
    return 0;
}