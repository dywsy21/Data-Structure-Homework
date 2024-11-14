#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int MOD = 1e9 + 7;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    size_t n, m; cin >> n >> m;
    size_t ans = 1;

    while(m) {
        if(m & 1) {
            ans *= n; ans %= MOD;
        }
        n *= n; n %= MOD;
        m >>= 1;
    }
    cout << ans;

    // system("pause");
    return 0;
}