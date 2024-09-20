#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n + 7);
    for(int i{1}; i <= n; i++) cin >> v[i];
    int cur_unfilled = 1, cur_to_merge_back = 2, ans = n;
    while(cur_to_merge_back <= n) {
        if(v[cur_unfilled] + v[cur_to_merge_back] <= k) {
            v[cur_unfilled] += v[cur_to_merge_back];
            cur_to_merge_back++, ans--;
        }
        else {
            cur_unfilled = cur_to_merge_back;
            cur_to_merge_back++;
        }
    }
    cout << ans;

    // system("pause");
    return 0;
}