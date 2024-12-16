#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7;
int a[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        for(int i {}; i < n; i++) cin >> a[i];
        
        priority_queue<int> pq(a, a + n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (i % (k + 1) != k) {
                ans += pq.top();
            }
            pq.pop();
        }
        cout << ans << '\n';
    }
    // system("pause");
    return 0;
}