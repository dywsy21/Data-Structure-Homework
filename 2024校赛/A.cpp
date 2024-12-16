#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i { n / 328}; i >= 0; i--)
        if((n - 328 * i) % 268 == 0) {
            cout << i;
            return 0;
        }

    cout << -1;

    // system("pause");
    return 0;
}