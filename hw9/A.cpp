#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    priority_queue<int> pq_large;
    priority_queue<int, vector<int>, greater<int>> pq_small;
    int cnt = 0;
    while(t--) {
        int op; cin >> op;
        if(op == 1) {
            int n; cin >> n; cnt++;
            if(pq_small.empty() or n >= pq_small.top()) pq_small.push(n);
            else pq_large.push(n);

            while(pq_large.size() > pq_small.size()) {
                pq_small.push(pq_large.top());
                pq_large.pop();
            }
            while(pq_small.size() > pq_large.size() + 1) {
                pq_large.push(pq_small.top());
                pq_small.pop();
            }
        }
        else if(cnt % 2) cout << pq_small.top() << '\n';
        else cout << pq_large.top() << '\n';
    }

    // system("pause");
    return 0;
}