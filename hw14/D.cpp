#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int count = 0;
    for(int l = 1; l < n; l++) {
        for(int r = l + 1; r <= n; r++) {
            cout << l << ' ' << r << '\n';
            count++;
            if(count == m) return 0;
        }
    }

    // system("pause");
    return 0;
}