#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int all_substr_nums = (s.size() * s.size() + s.size()) / 2;

    for(int start {}; start < s.size(); start++) {
        string sub = s.substr(start);
        vector<int> next(sub.size(), 0);
        int cur_max = 0;

        for(int i {1}; i < sub.size(); i++) {
            int j = next[i - 1];
            while(sub[i] != sub[j] && j) j = next[j - 1];
            if(sub[i] == sub[j]) next[i] = j + 1;
            all_substr_nums -= (next[i] > cur_max ? 1 : 0); // -1, only if this condition is met, to avoid duplicated truncating
            cur_max = max(cur_max, next[i]);
        }
    }
    cout << all_substr_nums << endl;
    return 0;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    
    int ans = 0;

    for(int sz {1}; sz <= s.size(); sz++) {
        unordered_set<string> substrs;
        for(int i {}; i + sz <= s.size(); i++) {
            substrs.insert(s.substr(i, sz));
        }
        ans += substrs.size();
    }
    cout << ans << endl;
    return 0;
}