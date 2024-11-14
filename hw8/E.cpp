#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 2e5 + 7;
int dp_neg[N], dp_pos[N], dp_zero[N], a[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i {1}; i <= n; i++) cin >> a[i];

    if(a[1] < 0) dp_neg[1] = 1;
    if(a[1] > 0) dp_pos[1] = 1;
    if(a[1] == 0) dp_zero[1] = 1;

    for(int i {2}; i <= n; i++) {
        if(a[i] < 0) {
            dp_neg[i] = dp_neg[i - 1] + (dp_pos[i - 1] - dp_pos[i - 2]) + 1;
            dp_pos[i] = dp_pos[i - 1] + (dp_neg[i - 1] - dp_neg[i - 2]);
            dp_zero[i] = dp_zero[i - 2] + (dp_zero[i - 1] - dp_zero[i - 2]) * 2;
        } 
        if(a[i] > 0) {
            dp_neg[i] = dp_neg[i - 1] + (dp_neg[i - 1] - dp_neg[i - 2]);
            dp_pos[i] = dp_pos[i - 1] + (dp_pos[i - 1] - dp_pos[i - 2]) + 1;
            dp_zero[i] = dp_zero[i - 2] + (dp_zero[i - 1] - dp_zero[i - 2]) * 2;
        } 
        if(a[i] == 0) {
            dp_neg[i] = dp_neg[i - 1];
            dp_pos[i] = dp_pos[i - 1];
            dp_zero[i] = dp_zero[i - 1] + i;
        } 
    }

    cout << dp_neg[n] << ' ' << dp_zero[n] << ' ' << dp_pos[n];

    return 0;
}