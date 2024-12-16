#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX_K = 32; // 最大不复习天数不可能超过20天，否则必大败
long long pw2[MAX_K + 1]; // 预计算2的幂次
int main() {
    int n; long long c; // 复习天数n，基础遗忘值c
    scanf("%d %lld", &n, &c);
    vector<long long> W(n), M(n); // 语文与数学每天的能力值
    for (int i = 0; i < n; i++) scanf("%lld", &W[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &M[i]);
    long long k = 1;
    for (int i = 0; i <= MAX_K; i++) { pw2[i] = k; k *= 2; } // 预计算2的幂次

    // dp_prev[k_C][k_M] 表示复习到当前一天为止，语文连续未复习k_C天，数学连续未复习k_M天的最大能力值
    vector<vector<long long>> dp_prev(MAX_K + 1, vector<long long>(MAX_K + 1, LLONG_MIN)); // 动态规划数组
    dp_prev[0][0] = 0; // 初始状态，均未复习，能力值之和为0
    
    for (int day = 0; day < n; day++) {
        vector<vector<long long>> dp_curr(MAX_K + 1, vector<long long>(MAX_K + 1, LLONG_MIN)); // 当天新动态规划数组
        for (int k_C = 0; k_C <= MAX_K; k_C++) { // 遍历所有可能的语文连续未复习天数
            for (int k_M = 0; k_M <= MAX_K; k_M++) { // 遍历所有可能的数学连续未复习天数
                if (k_C > 0 && k_M > 0) continue;
                // 实际上矩阵只有第一行和第一列有值，其余部分均为无效状态，因为不可能同时复习语文和数学
                if (dp_prev[k_C][k_M] == LLONG_MIN) continue; // 跳过无效状态
                
                long long current = dp_prev[k_C][k_M]; // 在这种情况下的当前能力值
                // 复习语文
                int new_k_M = min(k_M + 1, MAX_K); // 更新数学连续未复习天数
                long long forget_M = c * ((k_M < MAX_K) ? pw2[k_M] : pw2[MAX_K]); // 数学遗忘值（超过20天不管了）
                long long total_W = current + W[day] - forget_M; // 计算复习语文后的总能力值
                dp_curr[0][new_k_M] = max(dp_curr[0][new_k_M], total_W); // 更新复习语文的状态
                // 复习数学
                int new_k_C = min(k_C + 1, MAX_K); // 更新语文连续未复习天数
                long long forget_C = c * ((k_C < MAX_K) ? pw2[k_C] : pw2[MAX_K]); // 语文遗忘值
                long long total_M = current + M[day] - forget_C; // 计算复习数学后的总能力值
                dp_curr[new_k_C][0] = max(dp_curr[new_k_C][0], total_M); // 更新复习数学的状态
            }
        }
        dp_prev = move(dp_curr); // 更新dp_prev为当前天的dp_curr（move表示转移所有权）
    }
    
    long long ans = LLONG_MIN;  // 在所有可能的状态中找最大能力值
    for (int k_C = 0; k_C <= MAX_K; k_C++) {
        for (int k_M = 0; k_M <= MAX_K; k_M++) ans = max(ans, dp_prev[k_C][k_M]);
    }
    printf("%lld\n", ans);
    return 0;
}