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
};

struct WatchTower {
    int x, y, r;
};

bool isIntersecting(const WatchTower& tower1, const WatchTower& tower2) {
    int dx = tower1.x - tower2.x;
    int dy = tower1.y - tower2.y;
    int distSq = dx * dx + dy * dy;
    int radSumSq = (tower1.r + tower2.r) * (tower1.r + tower2.r);
    return distSq < radSumSq;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int p; cin >> p;
    vector<WatchTower> towers(p);
    for (int i = 0; i < p; ++i) {
        cin >> towers[i].x >> towers[i].y >> towers[i].r;
    }

    UnionFind uf(p + 4); // 4 extra for borders: left, right, top, bottom

    for (int i = 0; i < p; ++i) {
        if (towers[i].x - towers[i].r <= 0) uf.unite(i, p); // left border
        if (towers[i].x + towers[i].r >= n) uf.unite(i, p + 1); // right border
        if (towers[i].y - towers[i].r <= 0) uf.unite(i, p + 2); // bottom border
        if (towers[i].y + towers[i].r >= m) uf.unite(i, p + 3); // top border

        for (int j = i + 1; j < p; ++j) 
            if (isIntersecting(towers[i], towers[j])) 
                uf.unite(i, j);
    }

    if (uf.findRoot(p) == uf.findRoot(p + 1) || uf.findRoot(p + 2) == uf.findRoot(p + 3) || uf.findRoot(p) == uf.findRoot(p + 2) || uf.findRoot(p + 1) == uf.findRoot(p + 3) ) {
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }

    // system("pause");
    return 0;
}