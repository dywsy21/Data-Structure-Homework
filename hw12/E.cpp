#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 5e5 + 7; int a[N];

bool can_divide(int n, int k, int max_weight) {
    int cur_sum = 0, cur_segments = 1;
    for (int i = 0; i < n; i++) {
        if (cur_sum + a[i] > max_weight) {
            cur_segments++;
            cur_sum = a[i];
            if (cur_segments > k) return false;
        } else cur_sum += a[i];
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = *max_element(a, a + n), r = accumulate(a, a + n, 0LL), ans = r;

    // 二分答案
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (can_divide(n, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;
    // system("pause");
    return 0;
}