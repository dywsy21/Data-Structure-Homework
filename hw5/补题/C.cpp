#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

inline int min(int a, int b, int c) {
    return min(a, min(b, c));
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<int>> max_len(n, vector<int>(m, 1)); 
    for(int i {}; i < n; i++)
        for(int j {}; j < m; j++) 
            cin >> mat[i][j];

    int ans = 1;
    for(int i {1}; i < n; i++)
        for(int j {1}; j < m; j++) {
            max_len[i][j] = (mat[i][j] == mat[i][j - 1] and mat[i - 1][j - 1] == mat[i - 1][j] ? min(max_len[i - 1][j], max_len[i][j - 1], max_len[i - 1][j - 1]) + 1 : 1);
            ans = max(ans, max_len[i][j]);
        }
    
    cout << ans * ans;
    return 0;
}