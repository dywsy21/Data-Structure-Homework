#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long

const int MAXN = 5e5 + 7;
double a[MAXN], pre[MAXN];

typedef tree<pair<double, int>, null_type, less<pair<double, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i {}; i < n; i++) cin >> a[i];
    pre[0] = a[0];
    for(int i {1}; i < n; i++) pre[i] = pre[i - 1] + a[i];

    ordered_multiset s; int ans = 0; s.insert({0, -1});
    for(int i {}; i < n; i++) {
        // count valid answers within [[0, i], i]
        // s[i] - s[j] > 0 => s[j] < s[i]
        s.insert({pre[i], i});
        ans += s.order_of_key({pre[i] - 0.5, -1}); // order_of_key returns the number of elements smaller than the given element
    }

    cout << ans;

    // system("pause");
    return 0;
}