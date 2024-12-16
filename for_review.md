# 难题

1. 11-E
2. 12-D
3. ~~8-D~~

# 重要算法

1. 树的重心 —— 11-A
2. 树的直径 —— 11-B
3. lca —— 11-E
4. dijkstra —— 14
5. floyd —— 14
6. kruscal —— 15
7. 基数排序 —— 9-B

# 杂项

1. `tree`

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
    pair<int, int>, // pair<value, unique_id>
    null_type,
    less<pair<int, int>>, // 按值和唯一 ID 排序
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

// usage:
ordered_multiset s; s.insert({data, unique_id++});
```

2. `lower_bound`:

```cpp
auto it = lower_bound(v.begin(), v.end(), target);
int upper = *it, lower = *(--it); // target is in (lower, upper] / (*prev(it), *it]
```

3. `multiset` > `set`!
4. 记得可以二分答案 / 二分模板：

```cpp
    int l = *max_element(a, a + n), r = accumulate(a, a + n, 0LL), ans = r;

    // 二分答案
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (is_valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;
```

5. 字符串哈希，在$O(1)$时间内判断任意两个子串是否相等：

```cpp
const int base = 131;
int pw[N], hsh[N];

inline int gethash(int l, int r) {
    int len = r - l + 1;
    return hsh[r] - pw[len] * hsh[l - 1];
}

signed main() {
    string s; cin >> s;
    for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * base;
    for (int i = 1; i <= n; i++) hsh[i] = hsh[i - 1] * base + s[i] - 'a';
    ...
}

```

6. 并查集写法

```cpp
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
```

7. 记录图的数据的数据结构

- 邻接表

```cpp
vector<pair<int, int>> adj[N];
```

- 邻接矩阵

```cpp
int dist[N][N];
vector<vector<int>> dist(N, vector<int>(N, INF));
```

- 边集（for kruscal）

```cpp
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
vector<Edge> edges;
```

8. 单调栈: 栈里放pair存储元素和下标
9.  对顶堆 (9-A) -> 动态维护第k大的数，k可变

eg. 动态维护中位数：

```cpp
    priority_queue<int> pq_below;
    priority_queue<int, vector<int>, greater<int>> pq_top;
    int cnt = 0;
    while(t--) {
        int op; cin >> op;
        if(op == 1) {
            int n; cin >> n; cnt++;
            if(pq_top.empty() or n >= pq_top.top()) pq_top.push(n);
            else pq_below.push(n);

            while(pq_below.size() > pq_top.size()) {
                pq_top.push(pq_below.top());
                pq_below.pop();
            }
            while(pq_top.size() > pq_below.size() + 1) {
                pq_below.push(pq_top.top());
                pq_top.pop();
            }
        }
        else if(cnt % 2) cout << pq_top.top() << '\n';
        else cout << pq_below.top() << '\n';
    }
```

10. dp
11. 双指针

12. STL的`merge`: merge two sorted ranges into one sorted range, $O(n)$
13. `next`数组：

```cpp
    for(int i {1}; i < s.size(); i++) {
        int j = next[i - 1];
        while(s[i] != s[j] && j) j = next[j - 1];
        if(s[i] == s[j]) next[i] = j + 1;
    }
```

14. 块状链表`rope`:

```cpp
#include <ext/rope>
using namespace __gnu_cxx;

rope<int> r;
r.push_back(1);
r.push_back(2);
r.push_back(3);
r.erase(1, 1);
r.insert(1, 4);
```