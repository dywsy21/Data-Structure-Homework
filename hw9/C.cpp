#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

    // Directly take top K elements
    sort(a, a + n, greater<int>());
    cout << accumulate(a, a + k, 0LL);

    // system("pause");
    return 0;
}