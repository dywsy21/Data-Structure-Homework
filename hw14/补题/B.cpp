// 声明：参考了肖佳洲同学的写法
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 77, K = 77;
int mats[N][N][K];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i {1}; i <= n; i++) 
        for(int j {1}; j <= n; j++) 
            cin >> mats[i][j][1];
        

    // floyd revamp
    for(int k {2}; k <= n; k++)
        for(int i {1}; i <= n; i++)
            for(int j {1}; j <= n; j++) 
                for(int l {1}; l <= n; l++) 
                    if(mats[i][j][k] = mats[i][l][k - 1] && mats[l][j][1]) 
                        break;
                
    while(m--) {
        int x, k; cin >> x >> k;
        int sum = 0;
        for(int l {1}; l <= n; l++) sum += mats[x][l][k];
        cout << sum << '\n';
    }
    return 0;
}