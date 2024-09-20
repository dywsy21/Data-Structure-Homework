#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s; cin >> n >> s;

    auto hasDuplicateSubstring = [&](int length) {
        if (length == 0) return true;
        unordered_set<string> seen;
        int last_end = -1; // to ensure 2 substrs dont overlap
        for (int i = 0; i <= n - length; ++i) {
            string substring = s.substr(i, length);
            if (seen.count(substring) && i >= last_end) {
                return true;
            }
            seen.insert(substring);
            last_end = i + length;
        }
        return false;
    };

    int left = 0, right = n, ans = 0;
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
