#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

    // take Top k elements
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++) pq.push(a[i]);
    for(int i = k; i < n; i++){
        if(a[i] > pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }

    int sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum;

    // system("pause");
    return 0;
}