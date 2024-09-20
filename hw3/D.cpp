#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s; cin >> n >> s;

    auto hasDuplicateSubstring = [&](int length) {
        unordered_map<string, int> seen; // val = starting index
        for (int i = 0; i <= n - length; i++) {
            string substring = s.substr(i, length);
            if (seen.count(substring) && i >= seen[substring] + length) {
                return true;
            }
            seen[substring] = i;
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
