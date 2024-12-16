#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7, NO_CHOICE = -1, A = 0, B = 1;
int a[N], b[N];
int dp[N][2], state[N][2];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    for(int i {}; i < n; i++) cin >> a[i];
    for(int i {}; i < n; i++) cin >> b[i];
    
    dp[0][A] = a[0] - c;
    dp[0][B] = b[0] - c;
    state[0][A] = 1;
    state[0][B] = 1;

    for (int i = 1; i < n; ++i) {
        if (dp[i-1][A] - (1LL << state[i-1][A]) * c > dp[i-1][B] - c) {
            dp[i][A] = dp[i-1][A] - (1LL << state[i-1][A]) * c + a[i];
            state[i][A] = state[i-1][A] + 1;
        } 
        else {
            dp[i][A] = dp[i-1][B] - c + a[i];
            state[i][A] = 1;
        }

        if (dp[i-1][B] - (1LL << state[i-1][B]) * c > dp[i-1][A] - c) {
            dp[i][B] = dp[i-1][B] - (1LL << state[i-1][B]) * c + b[i];
            state[i][B] = state[i-1][B] + 1;
        } 
        else {
            dp[i][B] = dp[i-1][A] - c + b[i];
            state[i][B] = 1;
        }

        // Debug output
        cout << "Day " << i << ":\n";
        cout << "dp[" << i << "][A] = " << dp[i][A] << ", state[" << i << "][A] = " << state[i][A] << "\n";
        cout << "dp[" << i << "][B] = " << dp[i][B] << ", state[" << i << "][B] = " << state[i][B] << "\n";
    }

    int result = max(dp[n-1][A], dp[n-1][B]);
    cout << result << endl;

    // system("pause");
    return 0;
}