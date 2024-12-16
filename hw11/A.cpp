// 此份代码参考了课件PPT的代码
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> children[n + 1];
    for(int i {}; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        children[x].push_back(y);
        children[y].push_back(x);
    }

    int size[n + 1], max_subtree_size_of[n + 1], ans[2];
    ans[0] = ans[1] = 0;

    function<void(int, int)> getCentroid = [&](int cur, int father) {
        size[cur] = 1;
        max_subtree_size_of[cur] = 0;
        for(auto& child: children[cur]) if(child != father)  {
            getCentroid(child, cur);
            size[cur] += size[child];
            max_subtree_size_of[cur] = max(max_subtree_size_of[cur], size[child]);
        }
        max_subtree_size_of[cur] = max(max_subtree_size_of[cur], n - size[cur]);
        if(max_subtree_size_of[cur] <= n / 2) ans[ans[0] != 0] = cur;
    };

    getCentroid(1, -1);
    sort(ans, ans + 2);
    if(ans[0]) cout << ans[0] << ' ';
    cout << ans[1];

    // system("pause");
    return 0;
}