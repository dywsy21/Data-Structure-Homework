#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7, M = 32; // 2 ^ 30 > 1e9, so no longer than 30 days consecutive
int a[N], b[N], pre1[M + 1], pre2[M + 1];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    for(int i {}; i < n; i++) cin >> a[i];
    for(int i {}; i < n; i++) cin >> b[i];
    
    int ans = LLONG_MIN;

    // init dp to -INF
    for(int i {}; i < M + 1; i++) pre1[i] = pre2[i] = LLONG_MIN;
    pre1[0] = pre2[0] = 0;

    for (int i = 0; i < n; ++i) {
        int today1[M + 1], today2[M + 1];
        for(int j {}; j <= M ; j++) today1[j] = today2[j] = LLONG_MIN;
        
        for(int j {}; j < M; j++) if(pre1[j] != LLONG_MIN) {
            int forget_c = c * (1ll << min(j, M));
            today1[j + 1] = max(today1[j + 1], pre1[j] + b[i] - forget_c);
            today2[1] = max(today2[1], pre1[j] + a[i] - c);
        }

        for(int k {}; k < M; k++) if(pre2[k] != LLONG_MIN) {
            int forget_m = c * (1ll << min(k, M));
            today2[k + 1] = max(today2[k + 1], pre2[k] + a[i] - forget_m);
            today1[1] = max(today1[1], pre2[k] + b[i] - c);
        }

        // update dp
        for(int j {}; j <= M; j++) pre1[j] = today1[j];
        for(int j {}; j <= M; j++) pre2[j] = today2[j];
    }

    for(int i {}; i <= M; i++) ans = max({ans, pre1[i], pre2[i]});
    cout << ans;

    // system("pause");
    return 0;
}