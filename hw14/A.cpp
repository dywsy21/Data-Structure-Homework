// dijkstra template

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1007;
vector<pair<int, int>> adj[N]; // adjacency list
vector<int> dist(N, LLONG_MAX); // distance array

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, id
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); // 取出V-S中最近点
        pq.pop(); // 放入S中

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) { // 更新T的点（该点的所有非S的邻居）的最短路径长度
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // 此处涉及到的点dist不会是INF了，可以放入V-S
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijkstra(1);

    if (dist[n] == LLONG_MAX) cout << "Unreachable";
    else cout << dist[n];
    // system("pause");
    return 0;
}