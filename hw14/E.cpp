#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int MOD = 998244353, N = 1e5 + 7;

vector<int> next_nodes[N];
int dist[N], paths[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        next_nodes[u].push_back(v);
    }
    
    queue<int> q; q.push(1);
    dist[1] = 0; paths[1] = 1;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int v : next_nodes[u]) {
            if (dist[v] == 0) { // if not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            if (dist[v] == dist[u] + 1) paths[v] = (paths[v] + paths[u]) % MOD;
        }
    }
    
    for (int i = 1; i <= n; ++i) cout << paths[i] << " ";
    
    // system("pause");
    return 0;
}