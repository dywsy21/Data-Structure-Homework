#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, Q; cin >> n >> Q;
    vector<int> a(n); for(int& i: a) cin >> i;

    while(Q--) {
        int k; cin >> k;
        deque<int> dq; int sum = 0;
        for(int i {}; i < n; i++) {
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) sum += a[dq.front()];
        }
        cout << sum << '\n';
    }


    // system("pause");
    return 0;
}