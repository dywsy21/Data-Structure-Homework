#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

int n; const int N = 2007;
int x[N], y[N], c[N], k[N];

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
    
    // 视为图，每条边有权值(ki + kj) * (|xi - xj| + |yi - yj|)
    // 加一个伪节点，到每个节点的边权值为节点的权值ci
    // 求最小生成树即可

    cin >> n;
    for(int i {1}; i <= n; ++i) cin >> x[i] >> y[i];
    for(int i {1}; i <= n; ++i) cin >> c[i];
    for(int i {1}; i <= n; ++i) cin >> k[i];

    vector<Edge> edges;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int cost = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            edges.push_back({i, j, cost});
        }
    }
    for (int i = 1; i <= n; ++i) edges.push_back({0, i, c[i]});

    sort(edges.begin(), edges.end());

    // Kruskal:
    UnionFind uf(n + 1);

    int ans = 0;
    for (auto& edge : edges) {
        int u = edge.u, v = edge.v, cost = edge.w;
        if (!uf.isConnected(u, v)) {
            uf.unite(u, v);
            ans += cost;
        }
    }

    cout << ans;

    // system("pause");
    return 0;
}