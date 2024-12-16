#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7, M = 32; // 2 ^ 30 > 1e9, so no longer than 30 days consecutive
int a[N], b[N], pre[M + 1][M + 1];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    for(int i {}; i < n; i++) cin >> a[i];
    for(int i {}; i < n; i++) cin >> b[i];
    
    int ans = LLONG_MIN;

    // init dp to -INF
    for(int i {}; i < M + 1; i++)
        for(int j {}; j < M + 1; j++)
            pre[i][j] = LLONG_MIN;
    pre[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int today[M + 1][M + 1];

        // init today to -INF
        for(int j {}; j < M + 1; j++)
            for(int k {}; k < M + 1; k++)
                today[j][k] = LLONG_MIN;
        
        for(int j {}; j <= M; j++) if(pre[j][0] != LLONG_MIN) {
            // kc = j, km = 0
            int current = pre[j][0];
            int new_kc = min(j + 1, M);
            int forget_c = c * (1ll << min(j, M));
            int total_m = current + b[i] - forget_c;
            today[new_kc][0] = max(today[new_kc][0], total_m);
            int new_km = 1;
            int forget_m = c;
            int total_w = current + a[i] - forget_m;
            today[0][new_km] = max(today[0][new_km], total_w);

        }

        for(int k {}; k <= M; k++) if(pre[0][k] != LLONG_MIN) {
            // kc = 0, km = k
            int current = pre[0][k];
            int new_km = min(k + 1, M);
            int forget_m = c * (1ll << min(k, M));
            int total_w = current + a[i] - forget_m;
            today[0][new_km] = max(today[0][new_km], total_w);
            int new_kc = 1;
            int forget_c = c;
            int total_m = current + b[i] - forget_c;
            today[new_kc][0] = max(today[new_kc][0], total_m);

        }

        // update dp
        for(int j {}; j < M + 1; j++)
            for(int k {}; k < M + 1; k++)
                pre[j][k] = today[j][k];
    }

    for(int i {}; i <= M; i++)
        for(int j {}; j <= M; j++)
            ans = max(ans, pre[i][j]);

    cout << ans;

    // system("pause");
    return 0;
}