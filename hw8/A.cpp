#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int a; priority_queue<int> pq;
    for(int i {}; i < n; i++){
        cin >> a;
        pq.push(a);
    }

    while(m--) {
        int top = pq.top();
        pq.pop();
        pq.push(top / 2);
    }

    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    // system("pause");
    return 0;
}