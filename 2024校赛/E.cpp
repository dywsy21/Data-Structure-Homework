#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 2e5 + 7;
int a[N], pre_sum[N], pre_xor[N];

bool is_valid(int l, int r){
    // x ^ a == x ^ b?
    int a = pre_xor[r] ^ pre_xor[l - 1];
    int b = pre_sum[r] - pre_sum[l - 1];
    if(a < b) return false;
    int x = (a - b) / 2;
    return (x ^ a) == (x + b);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i {1}; i <= n; i++) cin >> a[i];

    for(int i {1}; i <= n; i++) pre_sum[i] = pre_sum[i - 1] + a[i];
    for(int i {1}; i <= n; i++) pre_xor[i] = pre_xor[i - 1] ^ a[i];

    int count = 0;
    for (int s = 1; s <= n; ++s) {
        for (int t = s; t <= s + 33 && t <= n; ++t) {
            if (is_valid(s, t)) {
                count++;
                // cout << s << ' ' << t << endl;
            }
        }
    }

    cout << count << endl;

    // system("pause");
    return 0;
}