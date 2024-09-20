#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;

    auto hasDuplicateSubstring = [&](int length) {
        if (length == 0) return true;
        unordered_set<string> seen;
        for (int i = 0; i <= n - length; ++i) {
            string substring = s.substr(i, length);
            if (seen.count(substring)) return true;
            seen.insert(substring);
        }
        return false;
    };

    int left = 0, right = n, result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (hasDuplicateSubstring(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;


    system("pause");
    return 0;
}
