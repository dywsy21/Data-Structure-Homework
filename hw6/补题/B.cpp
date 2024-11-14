#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;
int n, a[N], dp[N];

signed main() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    
    dp[1] = 0;
    deque<int> q1, q2;

    q1.push_back(1);
    q2.push_back(1);

    // 从第2号楼开始，进行动态规划
    for (int i = 2; i <= n; i++) {
        // 初始跳跃次数，假设从第i-1号楼直接跳过来
        dp[i] = dp[i - 1] + 1;

        // 处理符合条件2的跳跃,保证队列中的元素构成单调递增序列
        while (!q1.empty() && a[i] > a[q1.back()]) {
            dp[i] = min(dp[i], dp[q1.back()] + 1);
            q1.pop_back();
        }
        if (!q1.empty()) dp[i] = min(dp[i], dp[q1.back()] + 1);
        if (!q1.empty() and a[i] == a[q1.back()]) q1.pop_back();
        q1.push_back(i);

        // 处理符合条件3的跳跃,保证队列中的元素构成单调递减序列
        while (!q2.empty() && a[i] < a[q2.back()]) {
            dp[i] = min(dp[i], dp[q2.back()] + 1);
            q2.pop_back();
        }
        if (!q2.empty()) dp[i] = min(dp[i], dp[q2.back()] + 1);
        if (!q2.empty() and a[i] == a[q2.back()]) q2.pop_back();
        q2.push_back(i);
    }

    cout << dp[n];
    return 0;
}
