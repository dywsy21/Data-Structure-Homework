// LCA 算法部分参考了PPT
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int MAXN = 100005;
vector<int> adj[MAXN];
vector<pair<int, int>> edges;
int parent[MAXN], depth[MAXN], edge_count[MAXN];
int fa[MAXN][20]; // for LCA

void init(int root, int p) { // p: parent
    parent[root] = fa[root][0] = p;
    depth[root] = depth[p] + 1;
    for (int i = 1; i < 20; i++) fa[root][i] = fa[fa[root][i-1]][i-1];
    
    for (int u : adj[root]) if (u != p) init(u, root);
}

int lca(int u, int v) {
    // Phase 1
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) 
        if (depth[u] - (1 << i) >= depth[v]) 
            u = fa[u][i];
        
    if (u == v) return u;

    // Phase 2
    for (int i = 19; i >= 0; i--) if (fa[u][i] != fa[v][i]) {
        u = fa[u][i];
        v = fa[v][i];
    }
    return parent[u];
}

void add_path(int u, int v) {
    int l = lca(u, v);
    edge_count[u]++;
    edge_count[v]++;
    edge_count[l] -= 2;
}

void dfs_count(int start, int p) { // p: parent
    for (int neighbor : adj[start]) if (neighbor != p) {
        dfs_count(neighbor, start);
        edge_count[start] += edge_count[neighbor];
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    init(1, 0);

    int k; cin >> k;
    while (k--) {
        int a, b; cin >> a >> b;
        add_path(a, b);
    }

    dfs_count(1, 0);

    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        if (parent[u] == v) cout << edge_count[u] << " ";
        else cout << edge_count[v] << " ";
    }

    // system("pause");
    return 0;
}