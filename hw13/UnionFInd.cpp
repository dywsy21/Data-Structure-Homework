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
};
