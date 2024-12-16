#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

int n, m;
const int N = 1e5 + 7, M = 2e5 + 7;

vector<pair<int, int>> adj[N];
int dist[N];

void dijkstra(int start) {
    fill(dist, dist + N, LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    // 取出最近点，更新所有邻接点
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    dijkstra(1);
    int total_cost = 0;
    for (int i = 1; i <= n; ++i) total_cost += dist[i];
    cout << total_cost << '\n';
    // system("pause");
    return 0;
}