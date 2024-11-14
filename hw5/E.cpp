#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int next[n], ans[n]; for(int i {}; i < n; i++) cin >> next[i];
    
    int cur_max = 1;
    for(int i {}; i < n; i++) {
        if(next[i] == 0) ans[i] = cur_max++;
        else ans[i] = ans[next[i] - 1];
    }

    for(int i {}; i < n; i++) cout << ans[i] << ' ';
    return 0;
}