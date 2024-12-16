#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e6 + 7;
int a[N], idx[N]; bool destroyed[N];

class UnionFind {
    vector<int> root, size, sum; 
    int n;
public:
    int max_sum;

    UnionFind(int _n): n(_n), root(_n + 1), size(_n + 1, 1), sum(_n + 1), max_sum(0) {
        for(int i = 1; i <= _n; i++) {
            root[i] = i;
            sum[i] = a[i];
        }
    }
    
    void restore(int i) {
        max_sum = max(max_sum, sum[i]);
        if (i > 1 && !destroyed[i - 1]) unite(i - 1, i);
        if (i < n && !destroyed[i + 1]) unite(i, i + 1);
    }

    int findRoot(int x) {
        return x == root[x] ? x : root[x] = findRoot(root[x]);
    }

    void unite(int x, int y) {                      
        int x_root = findRoot(x), y_root = findRoot(y);
        if (x_root != y_root) {
            root[x_root] = y_root;
            size[y_root] += size[x_root];
            sum[y_root] += sum[x_root];
            max_sum = max(max_sum, sum[y_root]);
        }
    }
};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> idx[i];

    for (int i = 1; i <= n; i++) destroyed[idx[i]] = true;
    
    UnionFind uf(n);
    for (int i = 1; i <= n; i++) 
        if (!destroyed[i]) 
            uf.restore(i); // Set initial sum for non-destroyed elements

    vector<int> result(n + 1);
    for (int i = n; i >= 1; i--) {
        result[i] = uf.max_sum;
        int pos = idx[i];
        destroyed[pos] = false;
        uf.restore(pos); // Set sum for the newly restored element
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}