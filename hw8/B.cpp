#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n]; for(int i{}; i < n; i++) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> pq; // 小根堆

    int cur_sum = 0;
    for(int i {}; i < k; i++) {
        pq.push(a[i]);
        cur_sum += a[i];
    }

    cout << cur_sum << ' ';
    for(int i {k}; i < n; i++) {
        if(a[i] > pq.top()) {
            cur_sum -= pq.top(); cur_sum += a[i];
            pq.pop(); pq.push(a[i]);
        }
        cout << cur_sum << ' ';
    }
    
    // system("pause");
    return 0;
}