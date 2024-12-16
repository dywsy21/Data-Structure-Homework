#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // 1. find max i: 1 + 2 + ... + i <= n, using sqrt
        int i = (-1 + sqrt(1 + 8 * n)) / 2;
        if(i * (i + 1) / 2 == n) cout << i << '\n';
        else {
            i++;
            int pass_n = i * (i + 1) / 2;
            int diff = pass_n - n;
            if(i % 2 == 0) i += diff % 2;
            else i += 2 * (diff % 2);
            cout << i << '\n';




        }
    }


    // system("pause");
    return 0;
}