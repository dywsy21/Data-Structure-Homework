#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[n]; for(int i {}; i < n; i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i {}; i < n; i++) pq.push(a[i]);
    int sum = 0;
    while(pq.size() > 1) {
        int num1 = pq.top(); pq.pop();
        int num2 = pq.top(); pq.pop();
        pq.push(num1 + num2);
        sum += num1 + num2;
    }
    cout << sum;

    // system("pause");
    return 0;
}