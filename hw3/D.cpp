#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s; cin >> n >> s;

    auto hasDuplicateSubstring = [&](int length) {
        unordered_map<string, unordered_set<int>> seen; // val = starting indices
        for (int i = 0; i <= n - length; i++) {
            string substring = s.substr(i, length);
            if (seen.count(substring)) {
                for(int starting_index: seen[substring])
                    if(i >= starting_index + length)
                        return true;
            }
            seen[substring].insert(i);
        }
        return false;
    };    

    int left = 1, right = s.length() + 10, ans = 0;
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
