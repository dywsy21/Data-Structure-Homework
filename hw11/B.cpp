#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

vector<int> children[100005];
int max_depth, farthest_node;

void dfs(int node, int parent, int depth) {
    if (depth > max_depth) {
        max_depth = depth;
        farthest_node = node;
    }

    for (int child : children[node]) 
        if (child != parent) 
            dfs(child, node, depth + 1);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i {}; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        children[x].push_back(y);
        children[y].push_back(x);
    }

    // find the longest chain in the tree
    max_depth = -1; dfs(1, -1, 0);
    max_depth = -1; dfs(farthest_node, -1, 0);

    int total_cost = 2 * (n - 1) - max_depth;
    cout << total_cost << endl;

    // system("pause");
    return 0;
}