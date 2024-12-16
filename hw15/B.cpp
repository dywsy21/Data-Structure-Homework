#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

class UnionFind {        
    vector<int> root; int n;               
public:
    UnionFind(int _n): n(_n), root(_n) {
        for(int i = 0; i < _n; i++) root[i] = i;  
    }
    
    int findRoot(int x) {
        return x == root[x] ? x : root[x] = findRoot(root[x]);
    }

    void unite(int x, int y) {                      
        int x_root = findRoot(x), y_root = findRoot(y);
        root[x_root] = y_root;
    }

    bool isConnected(int x, int y) {                
        return findRoot(x) == findRoot(y);
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});
    }

    // Sort cities by their alert values
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Add the smallest au + av values to the edges
    priority_queue<Edge> pq;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n / (i + 1); ++j) 
            edges.push_back({idx[i], idx[j], a[idx[i]] + a[idx[j]]});

    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int total_cost = 0;
    int edge_count = 0;

    for (const auto& edge : edges) {
        if (!uf.isConnected(edge.u, edge.v)) {
            uf.unite(edge.u, edge.v);
            total_cost += edge.w;
            edge_count++;
            if (edge_count == n - 1) break;
        }
    }

    cout << total_cost;

    // system("pause");
    return 0;
}