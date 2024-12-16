#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 1e6 + 7, base = 131;
int pw[N], hsh[N], ans[N];

inline int gethash(int l, int r) {
    int len = r - l + 1;
    return hsh[r] - pw[len] * hsh[l - 1];
}

signed main() {
    int n, m; string s; cin >> n >> s;
    s = " " + s; m = (n + 1) / 2; pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * base;
    for (int i = 1; i <= n; i++) hsh[i] = hsh[i - 1] * base + s[i] - 'a';

    ans[m + 1] = -1;

    // ans[i] <= ans[i + 1] + 2
    // 那我们只需要在k从大到小的基础上先把ans[i]设为ans[i + 1] + 2，然后字符串哈希判断对不对，不对就一直减2即可
    for (int k = m; k; k--) {
        ans[k] = ans[k + 1] + 2;
        while (ans[k] >= 0 && k + ans[k] - 1 >= n - k + 1) ans[k] -= 2;
        while (ans[k] >= 0 && gethash(k, k + ans[k] - 1) != gethash(n - k + 1 - ans[k] + 1, n - k + 1)) ans[k] -= 2;
    }

    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
}