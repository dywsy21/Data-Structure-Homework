#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s; cin >> n >> s;

    auto hasDuplicateSubstring = [&](int length) {
        const int p = 31;
        const int m = 1e9 + 9;
        vector<int> p_pow(n);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++)
            p_pow[i] = (p_pow[i - 1] * p) % m;

        vector<long long> hashes(n + 1, 0);
        for (int i = 0; i < n; i++)
            hashes[i + 1] = (hashes[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

        unordered_map<long long, int> seen;
        for (int i = 0; i <= n - length; i++) {
            long long current_hash = (hashes[i + length] + m - hashes[i]) % m;
            current_hash = (current_hash * p_pow[n - i - 1]) % m;
            if (seen.count(current_hash) && i >= seen[current_hash] + length) {
                return true;
            }
            seen[current_hash] = i;
        }
        return false;
    };

    int left = 1, right = n, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (hasDuplicateSubstring(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans;

    // system("pause");
    return 0;
}
