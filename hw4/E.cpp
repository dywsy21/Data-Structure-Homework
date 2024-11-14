// NOTE: This solution referred to solutions online for the idea.
// The original solution is deprecated but stated below, and the new solution is implemented below.

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

// #define DEBUG

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        // solution of the next array from Question D
        vector<int> next(s.size(), 0);

        for(int i {1}; i < s.size(); i++) {
            int j = next[i - 1];
            while(s[i] != s[j] && j) j = next[j - 1];
            if(s[i] == s[j]) next[i] = j + 1;
        }

        int cycle_len = s.size() - next[s.size() - 1], ans; // remove the first cycle
        if(cycle_len <= s.size() / 2  // this means the first next[s.size() - 1] chars are adjacent / overlapping with the last next[s.size() - 1] chars
           && s.size() % cycle_len == 0  // this means the string is composed of cycles, to avoid strings like "ababa" being misjudged
        ) ans = 0;
        else ans = cycle_len - s.size() % cycle_len;

        cout << ans << '\n';

        //!DEPRECATED
        // string s1, s2; int index = 0, k = 0;

        // for(char c: s) {
        //     if(!s1.empty() && s1[index % s1.length()] == c){
        //         index %= s1.length(); index++; s2 += c;
        //     } 
        //     else {
        //         if(!s1.empty() && s1[k] == c) index = ++k, s2 += c;
        //         else s1 += s2, s2.clear(), index = 0, s1 += c, k = 0;
        //     }
        // }
        // cout << s1.length() - index << '\n';
    }
    // system("pause");
    return 0;
}
