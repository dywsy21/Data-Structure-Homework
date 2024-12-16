#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
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

    // system("pause");
    return 0;
}