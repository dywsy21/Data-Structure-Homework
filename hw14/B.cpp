#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int INF = 1e18;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n + 7, vector<int>(n + 7, INF)); // 邻接矩阵
    
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
    
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    for (int k = 1; k <= n; ++k) 
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << dist[i][j] << " ";
        cout << "\n";
    }

    // system("pause");
    return 0;
}